/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:28:02 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:37:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	read_elements(int fd, t_scene *scene, int *counter)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while ((line && !is_empty_line(line)) || *counter < 6)
	{
		if (!is_empty_line(line))
		{
			ret = process_element(line, scene, counter);
			if (!ret)
				return (free(line), empty_gnl_fd(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (*counter != 6)
		return (write(2, "Error\nMissing textures/colors\n", 31), 0);
	return (1);
}

int	read_map(int fd, t_map_data **data)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		ret = parse_map_line(line, data);
		free(line);
		if (!ret)
			return (empty_gnl_fd(fd), 0);
		line = get_next_line(fd);
	}
	if (!*data)
		return (write(2, "Error\nNo map found\n", 19), 0);
	if (!validate_map_reqs(*data))
		return (0);
	return (1);
}

int	load_file(int fd, t_scene *scene)
{
	int			counter;
	t_map_data	*data;

	counter = 0;
	data = NULL;
	if (!read_elements(fd, scene, &counter))
		return (0);
	if (!check_complete(&scene->textures))
		return (empty_gnl_fd(fd), 0);
	if (!read_map(fd, &data))
		return (free_list(data), 0);
	scene->arr_map = get_map(data, scene);
	free_list(data);
	if (!scene->arr_map)
		return (0);
	return (1);
}

int	check_map(char *filename, t_scene *scene)
{
	int	fd;
	int	ret;

	if (!has_extension(filename, ".cub"))
		return (write(2, "Error\n.cub file required\n", 25), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nCannot open file\n", 24), 0);
	ret = load_file(fd, scene);
	close(fd);
	if (!ret)
		return (0);
	scene->map = map_to_string(scene->arr_map, scene->map_height,
			scene->map_width);
	if (!scene->map)
		return (write(2, "Error\nMalloc allocation failed\n", 32), 0);
	clear_map(scene->map);
	free_dup(scene->arr_map, scene->map_height + HEIGHT_PADDING);
	return (1);
}

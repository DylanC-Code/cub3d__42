/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:28:56 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:37:13 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	process_element(char *line, t_scene *scene, int *counter)
{
	int	result;

	if (already_set(&scene->textures, line))
		return (write(2, "Error\nDuplicate texture/color\n", 31), 0);
	if (!valid_id(line))
		return (write(2, "Error\nInvalid texture/color syntax\n", 36), 0);
	(*counter)++;
	result = extract_element_data(line, &scene->textures);
	if (!result)
		return (write(2, "Error\nCouldn't parse .cub file properly\n", 41), 0);
	return (result);
}

int	check_complete(t_textures *st)
{
	if (!st->north)
		return (write(2, "Error\nMissing north texture\n", 29), 0);
	if (!st->south)
		return (write(2, "Error\nMissing south texture\n", 29), 0);
	if (!st->west)
		return (write(2, "Error\nMissing west texture\n", 28), 0);
	if (!st->east)
		return (write(2, "Error\nMissing east texture\n", 28), 0);
	if (!st->floor_set)
		return (write(2, "Error\nMissing floor color\n", 27), 0);
	if (!st->ceil_set)
		return (write(2, "Error\nMissing ceiling color\n", 29), 0);
	return (1);
}

void	empty_gnl_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	free_list(t_map_data *data)
{
	t_map_data	*temp;

	while (data)
	{
		temp = data;
		data = data->next;
		free(temp->line);
		free(temp);
	}
}

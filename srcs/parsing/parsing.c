/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-08 19:13:53 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-08 19:13:53 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*s_strndup(char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && len < n)
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*trim_spaces(char *str)
{
	char	*start;
	char	*end;
	char	*res;
	size_t	len;

	if (!str)
		return (NULL);
	start = str;
	while (*start == ' ' || *start == '\t')
		start++;
	end = str + ft_strlen(str);
	while (end > start && (end[-1] == ' ' || end[-1] == '\t' || end[-1] == '\n'))
		end--;
	len = end - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, start, len);
	res[len] = '\0';
	return (res);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	has_extension(char *filename, char *ext)
{
	int	len;
	int	ext_len;

	if (!filename || !ext)
		return (0);
	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len <= ext_len)
		return (0);
	return (ft_strncmp(filename + len - ext_len, ext, ext_len) == 0);
}

int	file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	only_spaces(char *line)
{
	while (*line && is_space(*line))
		line++;
	return (*line == 0 || *line == '\n');
}

int	is_forbidden_next(char letter, char next_char)
{
	if (letter == 'N' && next_char == 'O')
		return (1);
	if (letter == 'S' && next_char == 'O')
		return (1);
	if (letter == 'W' && next_char == 'E')
		return (1);
	if (letter == 'E' && next_char == 'A')
		return (1);
	if ((letter == 'N' && (next_char == 'S' || next_char == 'W' || 
		next_char == 'E' || next_char == 'A')) ||
		(letter == 'S' && (next_char == 'N' || next_char == 'W' || 
		next_char == 'E' || next_char == 'A')) ||
		(letter == 'W' && (next_char == 'N' || next_char == 'S' || 
		next_char == 'E' || next_char == 'A')) ||
		(letter == 'E' && (next_char == 'N' || next_char == 'S' || 
		next_char == 'W' || next_char == 'A')))
		return (1);
	return (0);
}

int	check_single_id(char *line, int i, char letter)
{
	int	j;

	if (line[i] != letter || !is_space(line[i + 1]))
		return (0);
	j = i + 1;
	while (is_space(line[j]))
		j++;
	if (line[j] == '\0' || line[j] == '\n')
		return (0);
	if (is_forbidden_next(letter, line[j]))
		return (0);
	return (1);
}

int	check_double_id(char *line, int i, char *id_str)
{
	if (ft_strncmp(&line[i], id_str, 2) != 0)
		return (0);
	return (is_space(line[i + 2]));
}

int	get_texture_id(char *line, int i)
{
	while (is_space(line[i]))
		i++;
	if (check_double_id(line, i, "NO"))
		return (0);
	if (check_double_id(line, i, "SO"))
		return (1);
	if (check_double_id(line, i, "WE"))
		return (2);
	if (check_double_id(line, i, "EA"))
		return (3);
	if (check_single_id(line, i, 'N'))
		return (0);
	if (check_single_id(line, i, 'S'))
		return (1);
	if (check_single_id(line, i, 'W'))
		return (2);
	if (check_single_id(line, i, 'E'))
		return (3);
	if (line[i] == 'F' && is_space(line[i + 1]))
		return (4);
	if (line[i] == 'C' && is_space(line[i + 1]))
		return (5);
	return (-1);
}

int	valid_id(char *line)
{
	return (get_texture_id(line, 0) != -1);
}

int	already_set(t_textures *st, char *line)
{
	int	id;

	id = get_texture_id(line, 0);
	if (id == 0)
		return (st->north != NULL);
	if (id == 1)
		return (st->south != NULL);
	if (id == 2)
		return (st->west != NULL);
	if (id == 3)
		return (st->east != NULL);
	if (id == 4)
		return (st->floor_set);
	if (id == 5)
		return (st->ceil_set);
	return (0);
}

int	xpm_file(char *path)
{
	if (!path)
		return (0);
	if (!has_extension(path, ".xpm"))
		return (write(2, "Error\nTexture must be .xpm file\n", 33), 0);
	if (!file_exists(path))
		return (write(2, "Error\nCannot open texture file\n", 32), 0);
	return (1);
}

int	store_texture_path(t_textures *st, int id, char *path)
{
	if (!xpm_file(path))
		return (free(path), 0);
	if (id == 0)
		st->north = path;
	else if (id == 1)
		st->south = path;
	else if (id == 2)
		st->west = path;
	else if (id == 3)
		st->east = path;
	else
		return (free(path), 0);
	return (1);
}

int	store_color_info(t_textures *st, int id, char *color_str)
{
	int	ret;

	if (id == 4)
		ret = set_color('F', color_str, st);
	else if (id == 5)
		ret = set_color('C', color_str, st);
	else
		ret = 0;
	free(color_str);
	return (ret);
}

int	set_element_data(t_textures *st, char *line, char *data)
{
	char	*trimmed;
	int		id;

	trimmed = trim_spaces(data);
	free(data);
	if (!trimmed)
		return (0);
	id = get_texture_id(line, 0);
	if (id >= 0 && id <= 3)
		return (store_texture_path(st, id, trimmed));
	if (id == 4 || id == 5)
		return (store_color_info(st, id, trimmed));
	return (free(trimmed), 0);
}

int	skip_elem_spaces(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	while (line[i] && !is_space(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

int	extract_element_data(char *line, t_textures *st)
{
	int		i;
	int		start;
	char	*data;

	i = skip_elem_spaces(line);
	if (!line[i] || line[i] == '\n')
		return (0);
	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	data = s_strndup(line + start, i - start);
	if (!data)
		return (0);
	return (set_element_data(st, line, data));
}


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


// void	free_scene(t_scene *scene)
// {
// 	int	i;

// 	if (!scene)
// 		return ;
// 	if (scene->textures)
// 	{
// 		free(scene->textures->north);
// 		free(scene->textures->south);
// 		free(scene->textures->west);
// 		free(scene->textures->east);
// 		free(scene->textures);
// 	}
// 	if (scene->map)
// 	{
// 		i = 0;
// 		while (scene->map[i])
// 		{
// 			free(scene->map[i]);
// 			i++;
// 		}
// 		free(scene->map);
// 	}
// 	free(scene);
// }

int	read_elements(int fd, t_scene *scene, int *counter)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line && *counter < 6)
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
	int			fd;
	int			ret;

	if (!has_extension(filename, ".cub"))
		return (write(2, "Error\n.cub file required\n", 25), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nCannot open file\n", 24), 0);
	ret = load_file(fd, scene);
	close(fd);
	if (!ret)
		return (0);
	scene->map = map_to_string(scene->arr_map, scene->map_height, scene->map_width);
	if(!scene->map)
		return (write(2, "Error\nMalloc allocation failed\n", 32), 0);
	clear_map(scene->map);
	free_dup(scene->arr_map, scene->map_height + HEIGHT_PADDING);
	return (1);
}

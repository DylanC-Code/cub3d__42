/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-17 08:56:47 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-17 08:56:47 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_map_dimensions(int *height, int *width, t_map_data *map)
{
	t_map_data	*head;
	size_t		len;
	size_t		current_len;

	head = map;
	len = 0;
	*height = 0;
	*width = 0;
	while (head)
	{
		(*height)++;
		current_len = 0;
		while (head->line[current_len] && head->line[current_len] != '\n')
			current_len++;
		if (current_len > len)
			len = current_len;
		head = head->next;
	}
	*width = len;
	if (*height == 0 || *width == 0)
		return (0);
	return (1);
}

int	alloc_rows(char **arr, int total_height, int total_width)
{
	int	i;

	i = 0;
	while (i < total_height)
	{
		arr[i] = malloc(total_width + 1);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			return (0);
		}
		ft_memset(arr[i], '-', total_width);
		arr[i][total_width] = '\0';
		i++;
	}
	return (1);
}

int	copy_line_to_map(char *dest, char *src, int start_pos, int max_width)
{
	int	i;
	int	j;

	i = 0;
	j = start_pos;
	while (src[i] && src[i] != '\n' && j < max_width)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	return (1);
}

int	fill_map_data(char **arr, t_map_data *map, int *dimensions)
{
	t_map_data	*head;
	int			row;
	int			left_pad;
	int			total_width;

	head = map;
	row = HEIGHT_PADDING / 2;
	left_pad = WIDTH_PADDING / 2;
	total_width = dimensions[WIDTH] + WIDTH_PADDING;
	while (head)
	{
		if (row < dimensions[HEIGHT] + (HEIGHT_PADDING / 2))
		{
			copy_line_to_map(arr[row], head->line, left_pad, total_width);
			row++;
		}
		head = head->next;
	}
	return (1);
}

int	fill_array(char **arr, t_map_data *map, int *dimensions)
{
	int	total_height;
	int	total_width;
	int	i;

	i = 0;
	total_height = dimensions[HEIGHT] + HEIGHT_PADDING;
	total_width = dimensions[WIDTH] + WIDTH_PADDING;
	if (!alloc_rows(arr, total_height, total_width))
		return (0);
	if (!fill_map_data(arr, map, dimensions))
	{
		while (i < total_height)
		{
			free(arr[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

char	**dup_map(char **map, int total_height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (total_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < total_height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[total_height] = NULL;
	return (copy);
}

void	free_dup(char **map, int total_height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < total_height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_players(char **map, int *dimensions)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = HEIGHT_PADDING / 2;
	while (y < dimensions[HEIGHT] + (HEIGHT_PADDING / 2))
	{
		x = WIDTH_PADDING / 2;
		while (x < dimensions[WIDTH] + (WIDTH_PADDING / 2))
		{
			if (ft_strchr("NSEW", map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	flood_check_outside(char **map, int *dims, int x, int y)
{
	int	map_start_x;
	int	map_start_y;

	if (y < 0 || x < 0)
		return (SUCCESS);
	if (y >= dims[HEIGHT] + HEIGHT_PADDING)
		return (SUCCESS);
	if (x >= dims[WIDTH] + WIDTH_PADDING)
		return (SUCCESS);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (SUCCESS);
	map_start_x = WIDTH_PADDING / 2;
	map_start_y = HEIGHT_PADDING / 2;
	if (x >= map_start_x && x < dims[WIDTH] + map_start_x &&
		y >= map_start_y && y < dims[HEIGHT] + map_start_y)
		if (ft_strchr("0NSEW", map[y][x]))
			return (ERROR);
	map[y][x] = 'X';
	if (flood_check_outside(map, dims, x + 1, y) == ERROR ||
		flood_check_outside(map, dims, x - 1, y) == ERROR ||
		flood_check_outside(map, dims, x, y + 1) == ERROR ||
		flood_check_outside(map, dims, x, y - 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	flood_check_inside(char **map, int *dims, int x, int y)
{
	int	map_start_x;
	int	map_start_y;
	int	map_end_x;
	int	map_end_y;

	map_start_x = WIDTH_PADDING / 2;
	map_start_y = HEIGHT_PADDING / 2;
	map_end_x = dims[WIDTH] + map_start_x;
	map_end_y = dims[HEIGHT] + map_start_y;
	if (x < map_start_x || x >= map_end_x)
		return (SUCCESS);
	if (y < map_start_y || y >= map_end_y)
		return (SUCCESS);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (SUCCESS);
	if (map[y][x] == ' ' || map[y][x] == '-' || map[y][x] == 'X')
		return (SUCCESS);
	if (!ft_strchr("0NSEW", map[y][x]))
		return (SUCCESS);
	map[y][x] = 'V';
	flood_check_inside(map, dims, x + 1, y);
	flood_check_inside(map, dims, x - 1, y);
	flood_check_inside(map, dims, x, y + 1);
	flood_check_inside(map, dims, x, y - 1);
	return (SUCCESS);
}

int	find_player_start(char **map, int *dims, int *px, int *py)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	y = HEIGHT_PADDING / 2;
	while (y < dims[HEIGHT] + (HEIGHT_PADDING / 2))
	{
		x = WIDTH_PADDING / 2;
		while (x < dims[WIDTH] + (WIDTH_PADDING / 2))
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				if (found)
					return (0);
				*px = x;
				*py = y;
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (found);
}

int	check_unreachable_spaces(char **map, int *dimensions)
{
	int	x;
	int	y;

	y = HEIGHT_PADDING / 2;
	while (y < dimensions[HEIGHT] + (HEIGHT_PADDING / 2))
	{
		x = WIDTH_PADDING / 2;
		while (x < dimensions[WIDTH] + (WIDTH_PADDING / 2))
		{
			if (map[y][x] == '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_enclosed(char **map, int *dimensions)
{
	char	**test_map;
	int		total_height;
	int		result;

	total_height = dimensions[HEIGHT] + HEIGHT_PADDING;
	test_map = dup_map(map, total_height);
	if (!test_map)
		return (ERROR);
	result = flood_check_outside(test_map, dimensions, 0, 0);
	free_dup(test_map, total_height);
	if (result == ERROR)
	{
		write(2, "Error\nMap not surrounded by walls\n", 35);
		return (ERROR);
	}
	return (SUCCESS);
}

int	is_reachable(char **map, int *dimensions)
{
	char	**test_map;
	int		total_height;
	int		player_x;
	int		player_y;

	total_height = dimensions[HEIGHT] + HEIGHT_PADDING;
	test_map = dup_map(map, total_height);
	if (!test_map)
		return (ERROR);
	player_x = 0;
	player_y = 0;
	if (!find_player_start(test_map, dimensions, &player_x, &player_y))
	{
		free_dup(test_map, total_height);
		write(2, "Error\nInvalid player position\n", 31);
		return (ERROR);
	}
	flood_check_inside(test_map, dimensions, player_x, player_y);
	if (!check_unreachable_spaces(test_map, dimensions))
	{
		free_dup(test_map, total_height);
		write(2, "Error\nUnreachable area(s) in map\n", 34);
		return (ERROR);
	}
	return (free_dup(test_map, total_height), SUCCESS);
}

int	validate_map(char **map, int *dimensions)
{
	int	player_count;

	player_count = count_players(map, dimensions);
	if (player_count == 0)
	{
		write(2, "Error\nNo starting position found\n", 34);
		return (ERROR);
	}
	if (player_count > 1)
	{
		write(2, "Error\nMultiple player positions\n", 33);
		return (ERROR);
	}
	if (is_enclosed(map, dimensions) == ERROR)
		return (ERROR);
	if (is_reachable(map, dimensions) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

char	**get_map(t_map_data *map, t_scene *sc)
{
	int		map_dimensions[2];
	char	**new_map;
	int		total_height;

	map_dimensions[HEIGHT] = 0;
	map_dimensions[WIDTH] = 0;
	(void)sc;
	if (!get_map_dimensions(&map_dimensions[HEIGHT], &map_dimensions[WIDTH], map))
		return (NULL);
	total_height = map_dimensions[HEIGHT] + HEIGHT_PADDING;
	new_map = malloc(sizeof(char *) * (total_height + 1));
	if (!new_map)
		return (NULL);
	new_map[total_height] = NULL;
	if (!fill_array(new_map, map, map_dimensions))
		return (free_dup(new_map, total_height), NULL);
	if (validate_map(new_map, map_dimensions) == ERROR)
		return (free_dup(new_map, total_height), NULL);
	return (new_map);
}

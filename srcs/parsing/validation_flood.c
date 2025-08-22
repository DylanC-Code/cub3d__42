/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_flood.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:35:14 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:35:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

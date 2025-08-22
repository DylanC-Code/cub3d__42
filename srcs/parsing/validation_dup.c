/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:34:39 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:34:48 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (x >= map_start_x && x < dims[WIDTH] + map_start_x && y >= map_start_y
		&& y < dims[HEIGHT] + map_start_y)
		if (ft_strchr("0NSEW", map[y][x]))
			return (ERROR);
	map[y][x] = 'X';
	if (flood_check_outside(map, dims, x + 1, y) == ERROR
		|| flood_check_outside(map, dims, x - 1, y) == ERROR
		|| flood_check_outside(map, dims, x, y + 1) == ERROR
		|| flood_check_outside(map, dims, x, y - 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	flood_check_inside(char **map, int *dims, int x, int y)
{
	int	map_end_x;
	int	map_end_y;

	map_end_x = dims[WIDTH] + WIDTH_PADDING / 2;
	map_end_y = dims[HEIGHT] + HEIGHT_PADDING / 2;
	if (x < WIDTH_PADDING / 2 || x >= map_end_x)
		return (SUCCESS);
	if (y < HEIGHT_PADDING / 2 || y >= map_end_y)
		return (SUCCESS);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (SUCCESS);
	if (map[y][x] == ' ')
		return (ERROR);
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

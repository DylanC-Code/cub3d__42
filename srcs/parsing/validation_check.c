/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:35:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:37:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space_valid(char **map, int *dims, int x, int y)
{
	if (x > 0 && ft_strchr("0NSEW", map[y][x - 1]))
		return (ERROR);
	if (x < dims[WIDTH] + WIDTH_PADDING - 1 && ft_strchr("0NSEW", map[y][x
			+ 1]))
		return (ERROR);
	if (y > 0 && ft_strchr("0NSEW", map[y - 1][x]))
		return (ERROR);
	if (y < dims[HEIGHT] + HEIGHT_PADDING - 1 && ft_strchr("0NSEW", map[y
				+ 1][x]))
		return (ERROR);
	return (SUCCESS);
}

int	validate_spaces(char **map, int *dimensions)
{
	int	x;
	int	y;

	y = HEIGHT_PADDING / 2;
	while (y < dimensions[HEIGHT] + (HEIGHT_PADDING / 2))
	{
		x = WIDTH_PADDING / 2;
		while (x < dimensions[WIDTH] + (WIDTH_PADDING / 2))
		{
			if (map[y][x] == ' ' && !is_space_valid(map, dimensions, x, y))
				return (write(2, "Error\nInvalid space next to walkable area\n",
						42), ERROR);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	validate_map(char **map, int *dimensions)
{
	int	player_count;

	player_count = count_players(map, dimensions);
	if (player_count == 0)
		return (write(2, "Error\nNo starting position found\n", 34), ERROR);
	if (player_count > 1)
		return (write(2, "Error\nMultiple player positions\n", 33), ERROR);
	if (is_enclosed(map, dimensions) == ERROR)
		return (ERROR);
	if (!validate_spaces(map, dimensions))
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
	if (!get_map_dimensions(&map_dimensions[HEIGHT], &map_dimensions[WIDTH],
			map))
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
	sc->map_height = map_dimensions[HEIGHT] + HEIGHT_PADDING;
	sc->map_width = map_dimensions[WIDTH] + WIDTH_PADDING;
	return (new_map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-19 13:09:46 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-19 13:09:46 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int flood_fill_asdf(char **map, int *dimensions, int x, int y)
{
	if (y <= 0 || x <= 0 || y >= dimensions[HEIGHT] + HEIGHT_PADDING - 1 
		|| x >= dimensions[WIDTH] + WIDTH_PADDING - 1)
		return SUCCESS;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return SUCCESS;
	if (ft_strchr("0NSEW ", map[y][x]))
		return ERROR;
	map[y][x] = 'X';
	if (!
		flood_fill_asdf(map, dimensions, x + 1, y)||
		!flood_fill_asdf(map, dimensions, x - 1, y)||	
		!flood_fill_asdf(map, dimensions, x, y + 1)||
		!flood_fill_asdf(map, dimensions, x, y - 1)
	)
	return ERROR;
	return SUCCESS;
}
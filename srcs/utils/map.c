/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-21 03:10:55 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-21 03:10:55 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char *map_to_string(char **map, int height, int width)
{
	char *result;
	int total_size = height * width;
	int pos = 0;

	result = malloc(total_size + 1);
	if (!result)
		return (NULL);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			result[pos++] = map[i][j];
		}
	}
	result[total_size] = '\0';
	return (result);
}

void clear_map(char *map)
{
	int i;

	i = 0;
	while(map[i])
	{
		if(!ft_strchr("0NSEW", map[i]))
			map[i] = '1';
		i++;
	}
}

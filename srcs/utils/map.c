/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 03:10:55 by saal-kur          #+#    #+#             */
/*   Updated: 2025/08/22 10:05:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*map_to_string(char **map, int height, int width)
{
	char	*result;
	int		total_size;
	int		pos;
	int		i;
	int		j;

	j = 0;
	i = 0;
	total_size = height * width;
	pos = 0;
	result = malloc(total_size + 1);
	if (!result)
		return (NULL);
	while (i < height)
	{
		j = -1;
		while (++j < width)
			result[pos++] = map[i][j];
		i++;
	}
	result[total_size] = '\0';
	return (result);
}

void	clear_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_strchr("0NSEW", map[i]))
			map[i] = '1';
		i++;
	}
}

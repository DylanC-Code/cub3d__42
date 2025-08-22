/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_dimensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:33:39 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:33:49 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

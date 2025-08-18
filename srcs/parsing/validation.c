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

int get_map_dimensions(int *dimensions, t_map_data *map)
{
	t_map_data *head;
	char *clean_line;
	size_t len;

	head = map;
	len = 0;
	dimensions[HEIGHT] = 0;
	while (head)
	{
		dimensions[HEIGHT]++;
		clean_line = clean_copy(head->line);
		if (!clean_line)
			return 0;
		if (ft_strlen(clean_line) > len)
			len = ft_strlen(clean_line);
		free(clean_line);
		head = head->next;
	}
	dimensions[WIDTH] = len;
	return 1;
}

char *clean_copy(char *str)
{
	int len;
	char *res;
	int i;
	int j;

	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return NULL;
	i = 0, j = 0;

	while (i < len)
	{
		if (!is_space(str[i]))
			res[j++] = str[i++];
		else
			i++;
	}
	res[j] = 0;
	return res;
}

int alloc_rows(char **arr, int total_height, int total_width)
{
	int i;

	i = 0;
	while (i < total_height)
	{
		arr[i] = malloc(total_width + 1);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			return 0;
		}
		ft_memset(arr[i], ' ', total_width);
		arr[i][total_width] = '\0';
		i++;
	}
	return 1;
}

int fill_map_data(char **arr, t_map_data *map)
{
	t_map_data *head;
	char *clean_line;
	int row;
	int left_pad;

	head = map;
	row = HEIGHT_PADDING / 2;
	left_pad = WIDTH_PADDING / 2;
	while (head)
	{
		clean_line = clean_copy(head->line);
		if (!clean_line)
			return 0;
		ft_strlcpy(arr[row] + left_pad, clean_line, ft_strlen(clean_line) + 1);
		free(clean_line);
		row++;
		head = head->next;
	}
	return 1;
}

int fill_array(char **arr, t_map_data *map, int *dimensions)
{
	int total_height;
	int total_width;
	int i;

	i = 0;
	total_height = dimensions[HEIGHT] + HEIGHT_PADDING;
	total_width = dimensions[WIDTH] + WIDTH_PADDING;

	if (!alloc_rows(arr, total_height, total_width))
		return 0;

	if (!fill_map_data(arr, map))
	{
		while (i < total_height)
		{
			free(arr[i]);
			i++;
		}
		return 0;
	}
	return 1;
}

char **get_map(t_map_data *map, t_scene *sc)
{
	int map_dimensions[2];
	char **new_map;
	int total_height;

	(void)sc;
	if (!get_map_dimensions(map_dimensions, map))
		return NULL;
	total_height = map_dimensions[HEIGHT] + HEIGHT_PADDING;
	new_map = malloc(sizeof(char *) * (total_height + 1));
	if (!new_map)
		return NULL;
	new_map[total_height] = NULL;
	if (!fill_array(new_map, map, map_dimensions))
	{
		free(new_map);
		return NULL;
	}
	return new_map;
}

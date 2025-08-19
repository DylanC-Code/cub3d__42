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

int get_map_dimensions(int *height, int *width, t_map_data *map)
{
	t_map_data *head;
	char *clean_line;
	size_t len;

	head = map;
	len = 0;
	while (head)
	{
		(*height)++;
		clean_line = clean_copy(head->line);
		if (!clean_line)
			return 0;
		if (ft_strlen(clean_line) > len)
			len = ft_strlen(clean_line);
		free(clean_line);
		head = head->next;
	}
	*width = len;
	return 1;
}

char *clean_copy(char *str)
{
	int len;
	char *res;
	int i;

	len = ft_strlen(str);
	res = malloc(len + 1);
	i = 0;
	if (!res)
		return NULL;

	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return res;
}

int alloc_rows(char **arr, int total_height, int total_width, t_map_data *map)
{
	int i;
	i = 0;
	(void)map;
	printf("total - width ->%d\n", total_width);
	while (i < total_height)
	{
		arr[i] = malloc(total_width + 1);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			return 0;
		}
		ft_memset(arr[i], '-', total_width);
		arr[i][total_width] = '\0';
		i++;
	}
	return 1;
}
#include <string.h>

int fill_map_data(char **arr, t_map_data *map, int size)
{
	t_map_data *head;
	int row;
	int left_pad;
(void)size;
	head = map;
	row = HEIGHT_PADDING/2;
	left_pad = WIDTH_PADDING / 2;
	while (head)
	{
		if(row < size - (HEIGHT_PADDING / 2))
		{
			strncpy(arr[row] + left_pad, head->line, ft_strlen(head->line) -1 );
			// arr[row][ft_strlen(arr[row]) -1] = '\n';
			row++;
		}
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

	if (!alloc_rows(arr, total_height, total_width, map))
		return 0;

	if (!fill_map_data(arr, map, total_height))
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

	map_dimensions[HEIGHT] = 0;
	map_dimensions[WIDTH] = 0;
	(void)sc;
	if (!get_map_dimensions(&map_dimensions[HEIGHT], &map_dimensions[WIDTH], map))
		return NULL;
	total_height = map_dimensions[HEIGHT] + HEIGHT_PADDING;
	printf("H->%d W->%d\n", map_dimensions[HEIGHT], map_dimensions[WIDTH]);
	new_map = malloc(sizeof(char *) * (total_height + 1));
	if (!new_map)
		return NULL;
	new_map[total_height] = NULL;
	if (!fill_array(new_map, map, map_dimensions))
	{
		free(new_map);
		return NULL;
	}

	int s = flood_fill_asdf(new_map,map_dimensions,1,1);
	printf("SUCCESS == %d\n", s == SUCCESS);
		//return NULL; //TODO: free everything
	// for(int i = 0; new_map[i]; i++)
	// 	printf("%s\n", new_map[i]);
	return new_map;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-16 09:30:25 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-16 09:30:25 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char *trim_str(char *str)
{
	char *start;
	char *end;

	start = str;
	while (*start && is_space(*start))
		start++;
	end = start + ft_strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		*end = '\0';
		end--;
	}
	return start;
}

int is_valid_number(char *str)
{
	int i;
	int num;
	char *trimmed;

	i = 0;
	if (!str || !str[0])
		return 0;
	trimmed = trim_str(str);
	while (trimmed[i])
	{
		if (trimmed[i] < '0' || trimmed[i] > '9')
			return 0;
		i++;
	}
	num = ft_atoi(trimmed); 
	if (num < 0 || num > 255)
		return 0;
	return 1;
}

void free_arr(char **colors)
{
	int i;
	
	i = 0;
	while(colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
}

int check_color_format(char *line)
{
	char **colors;
	int i;
	int valid;

	
	colors = ft_split(line, ',');
	if (!colors)
	return 0;
	i = 0;
	valid = 1;
	while (colors[i])
	{
		if (!is_valid_number(colors[i]))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	printf("[VALID : %d] %s\n", valid, line);
	if (i != 3)
		valid = 0;
	free_arr(colors);
	return valid;
}

int set_color(char id, char *color, t_textures *st)
{
	char **colors;
	int rgb[3];
	int color_value;

	if (!check_color_format(color))
	{
		printf("Error: Invalid color format\n");
		return 0;
	}
	colors = ft_split(color, ',');
	if (!colors)
		return printf("Error: malloc failure\n"), 0;
	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2 ]= ft_atoi(colors[2]);
	color_value = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	if (id == 'F')
		st->floor_color = color_value;
	else if (id == 'C')
		st->ceil_color = color_value;
	free_arr(colors);
	return 1;
}

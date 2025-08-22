/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:30:25 by saal-kur          #+#    #+#             */
/*   Updated: 2025/08/22 10:06:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_number(char *str, int *i, int *value)
{
	int	num;
	int	digits;

	*i = skip_spaces(str, *i);
	if (!str[*i] || str[*i] < '0' || str[*i] > '9')
		return (0);
	if (str[*i] == '0' && str[*i + 1] >= '0' && str[*i + 1] <= '9')
		return (0);
	num = 0;
	digits = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + (str[*i] - '0');
		if (num > 255)
			return (0);
		(*i)++;
		digits++;
		if (digits > 3)
			return (0);
	}
	*value = num;
	return (1);
}

int	parse_rgb(char *str, int *r, int *g, int *b)
{
	int	i;

	i = 0;
	if (!parse_number(str, &i, r))
		return (0);
	i = skip_spaces(str, i);
	if (str[i] != ',')
		return (0);
	i++;
	if (!parse_number(str, &i, g))
		return (0);
	i = skip_spaces(str, i);
	if (str[i] != ',')
		return (0);
	i++;
	if (!parse_number(str, &i, b))
		return (0);
	i = skip_spaces(str, i);
	if (str[i] && str[i] != '\n')
		return (0);
	return (1);
}

int	store_color(char id, t_textures *st, int color_value)
{
	if (id == 'F')
	{
		st->floor_color = color_value;
		st->floor_set = 1;
	}
	else if (id == 'C')
	{
		st->ceil_color = color_value;
		st->ceil_set = 1;
	}
	else
		return (0);
	return (1);
}

int	set_color(char id, char *color, t_textures *st)
{
	int	r;
	int	g;
	int	b;
	int	color_value;

	r = 0;
	g = 0;
	b = 0;
	if (!parse_rgb(color, &r, &g, &b))
		return (write(2, "Error\nInvalid color format\n", 28), 0);
	color_value = create_trgb(0, r, g, b);
	return (store_color(id, st, color_value));
}

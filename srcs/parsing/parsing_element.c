/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:29:21 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:29:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	store_color_info(t_textures *st, int id, char *color_str)
{
	int	ret;

	if (id == 4)
		ret = set_color('F', color_str, st);
	else if (id == 5)
		ret = set_color('C', color_str, st);
	else
		ret = 0;
	free(color_str);
	return (ret);
}

int	set_element_data(t_textures *st, char *line, char *data)
{
	char	*trimmed;
	int		id;

	trimmed = trim_spaces(data);
	free(data);
	if (!trimmed)
		return (0);
	id = get_texture_id(line, 0);
	if (id >= 0 && id <= 3)
		return (store_texture_path(st, id, trimmed));
	if (id == 4 || id == 5)
		return (store_color_info(st, id, trimmed));
	return (free(trimmed), 0);
}

int	skip_elem_spaces(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	while (line[i] && !is_space(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

int	extract_element_data(char *line, t_textures *st)
{
	int		i;
	int		start;
	char	*data;

	i = skip_elem_spaces(line);
	if (!line[i] || line[i] == '\n')
		return (0);
	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	data = s_strndup(line + start, i - start);
	if (!data)
		return (0);
	return (set_element_data(st, line, data));
}

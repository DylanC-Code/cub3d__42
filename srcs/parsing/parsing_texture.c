/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:29:51 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:30:40 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_id(char *line)
{
	return (get_texture_id(line, 0) != -1);
}

int	already_set(t_textures *st, char *line)
{
	int	id;

	id = get_texture_id(line, 0);
	if (id == 0)
		return (st->north != NULL);
	if (id == 1)
		return (st->south != NULL);
	if (id == 2)
		return (st->west != NULL);
	if (id == 3)
		return (st->east != NULL);
	if (id == 4)
		return (st->floor_set);
	if (id == 5)
		return (st->ceil_set);
	return (0);
}

int	xpm_file(char *path)
{
	if (!path)
		return (0);
	if (!has_extension(path, ".xpm"))
		return (write(2, "Error\nTexture must be .xpm file\n", 33), 0);
	if (!file_exists(path))
		return (write(2, "Error\nCannot open texture file\n", 32), 0);
	return (1);
}

int	store_texture_path(t_textures *st, int id, char *path)
{
	if (!xpm_file(path))
		return (free(path), 0);
	if (id == 0)
		st->north = path;
	else if (id == 1)
		st->south = path;
	else if (id == 2)
		st->west = path;
	else if (id == 3)
		st->east = path;
	else
		return (free(path), 0);
	return (1);
}

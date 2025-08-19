/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:11:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 11:20:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_one(t_game *game, t_image *dst, char *path)
{
	dst->img = mlx_xpm_file_to_image(game->mlx, path, &dst->width,
			&dst->height);
	if (!dst->img)
		exit_error("Loading image",game);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp, &dst->line_len,
			&dst->endian);
}

void	load_walls_textures(t_game *g)
{
	load_one(g, &g->scene.walls.north, g->scene.textures.north);
	load_one(g, &g->scene.walls.south, g->scene.textures.south);
	load_one(g, &g->scene.walls.east, g->scene.textures.east);
	load_one(g, &g->scene.walls.west, g->scene.textures.west);
}

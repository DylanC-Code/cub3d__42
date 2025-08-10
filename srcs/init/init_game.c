/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:55:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 10:14:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("mlx_init", game);
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	game->window = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3d");
	if (!game->window)
		exit_error("mlx_init", game);
	load_walls_textures(game);
	create_image(game, &game->render, game->screen_width, game->screen_height);
	create_image(game, &game->render_hud, game->scene.map_width * TILE_SIZE,
		game->scene.map_height * TILE_SIZE);
	set_background_color(game, 0x0000FFFF);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:44:21 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/09 14:26:30 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define LINE_LENGTH 30

static void	render_vue_line(t_game *game)
{
	t_coordinates	start;
	t_coordinates	end;

	start.x = game->player.pos.x * 32 + 4;
	start.y = game->player.pos.y * 32 + 4;
	end.x = start.x + cos(game->player.angle) * LINE_LENGTH;
	end.y = start.y - sin(game->player.angle) * LINE_LENGTH;
	put_line(&game->render_hud, &start, &end, 0x00E85AD6);
}

void	render_player(t_game *game)
{
	t_coordinates	player_off;

	player_off.x = game->player.pos.x * 32;
	player_off.y = game->player.pos.y * 32;
	put_square(&game->render_hud, &player_off, 8, 0x00F5E170);
	render_vue_line(game);
	// mlx_put_image_to_window(game->mlx, game->window, game->render.img, 0, 0);
}

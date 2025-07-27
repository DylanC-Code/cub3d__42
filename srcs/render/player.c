/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:44:21 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:03:59 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_game *game)
{
	t_image	player_img;

	create_image(game, &player_img, 8, 8);
	fill_image(&player_img, 0x00F5E170);
	mlx_put_image_to_window(game->mlx, game->window, player_img.img,
		game->player.pos.x * 32, game->player.pos.y * 32);
}

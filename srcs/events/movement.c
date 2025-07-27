/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:13:07 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 12:22:34 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	degToRad(int a)
{
	return (a * PI / 180.0);
}

void	move_right(t_game *game)
{
	game->player.angle -= 0.1;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	game->player.delta.x = cos(game->player.angle) * MOVE_SPEED;
	game->player.delta.y = -sin(game->player.angle) * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	game->player.angle += 0.1;
	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	game->player.delta.x = cos(game->player.angle) * MOVE_SPEED;
	game->player.delta.y = -sin(game->player.angle) * MOVE_SPEED;
}

void	move_up(t_game *game)
{
	game->player.pos.y += game->player.delta.y;
	game->player.pos.x += game->player.delta.x;
}

void	move_down(t_game *game)
{
	game->player.pos.y -= game->player.delta.y;
	game->player.pos.x -= game->player.delta.x;
}

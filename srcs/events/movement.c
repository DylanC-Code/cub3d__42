/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:13:07 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:27:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_game *game)
{
	game->player.pos.x -= 0.1;
	// render_player(game);
}

void	move_right(t_game *game)
{
	game->player.pos.x += 0.1;
	// render_player(game);
}

void	move_up(t_game *game)
{
	game->player.pos.y -= 0.1;
	// render_player(game);
}

void	move_down(t_game *game)
{
	game->player.pos.y += 0.1;
	// render_player(game);
}

// void	move(t_game *game, char *player, char *destination)
// {
// 	if (*destination == WALL)
// 		return ;
// 	if (*destination == EXIT || *destination == FIRE)
// 	{
// 		print_move_counter(++game->player.moves);
// 		exit_game(game);
// 	}
// 	game->player.is_moving = TRUE;
// 	collect_item(game, destination);
// 	*player = EMPTY;
// 	*destination = PLAYER;
// 	print_move_counter(++game->player.moves);
// 	render_hud(game);
// 	render_map(game);
// }

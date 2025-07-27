/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:23:25 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:59:41 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	render_frame(void *param)
// {
// 	static int	frame_count = 0;
// 	t_game		*game;

// 	game = param;
// 	if (frame_count++ < 10)
// 		return (0);
// 	frame_count = 0;
// 	display_game(game);
// 	return (0);
// }

int	display_game(t_game *game)
{
	display_hud(game);
	return (SUCCESS);
}

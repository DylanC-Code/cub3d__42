/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:14:18 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 10:30:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	t_coordinates	map_pos;
	t_coordinates	el_pos;
	t_coordinates	el_pos_off;

	map_pos.x = 0;
	map_pos.y = 0;
	put_square(&game->render_hud, &map_pos, 32 * game->scene.map_width,
		0x003890f5);
	el_pos.y = -1;
	while (++el_pos.y < game->scene.map_height + HEIGHT_PADDING)
	{
		el_pos.x = -1;
		while (++el_pos.x < game->scene.map_width + WIDTH_PADDING)
		{
			el_pos_off.x = 1 + el_pos.x * 32;
			el_pos_off.y = 1 + el_pos.y * 32;
			if (game->scene.map[
				((int)el_pos.y) * game->scene.map_width + (int)el_pos.x
			]  == WALL)
				put_square(&game->render_hud, &el_pos_off, 30, 0x00FFFFFF);
			else
				put_square(&game->render_hud, &el_pos_off, 30, 0x00000000);
		}
	}
}

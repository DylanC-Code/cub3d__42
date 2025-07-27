/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:14:18 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 10:42:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_game *game)
{
	t_image	image_map;
	int		x_y[2];
	int		x_y_off[2];

	create_image(game, &image_map, 32 * game->scene.map_width, 32
		* game->scene.map_height);
	fill_image(&image_map, 0x003890f5);
	x_y[1] = -1;
	while (++x_y[1] < game->scene.map_height)
	{
		x_y[0] = -1;
		while (++x_y[0] < game->scene.map_width)
		{
			x_y_off[0] = 1 + x_y[0] * 32;
			x_y_off[1] = 1 + x_y[1] * 32;
			if (game->scene.map[x_y[1] * game->scene.map_width
				+ x_y[0]] == WALL)
				put_square(&image_map, x_y_off, 30, 0x00FFFFFF);
			else
				put_square(&image_map, x_y_off, 30, 0x00000000);
		}
	}
	mlx_put_image_to_window(game->mlx, game->window, image_map.img, 0, 0);
	// game->screen_height - 32 * game->scene.map_width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 15:33:00 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_image(t_image *img, int color)
{
	t_coordinates	pos;

	pos.y = 0;
	while (pos.y < img->height)
	{
		pos.x = 0;
		while (pos.x < img->width)
		{
			put_pixel(img, &pos, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	set_background_color(t_game *game, int color)
{
	fill_image(&game->render, color);
	mlx_put_image_to_window(game->mlx, game->window, game->render.img, 0, 0);
}

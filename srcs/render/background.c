/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:54:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 22:03:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_image(t_image *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			put_pixel(img, x++, y, color);
		y++;
	}
}

void	set_background_color(t_game *game, int color)
{
	t_image	image;

	ft_bzero(&image, sizeof(t_image));
	create_image(game, &image, game->screen_width, game->screen_height);
	fill_image(&image, color);
	mlx_put_image_to_window(game->mlx, game->window, image.img, 0, 0);
}

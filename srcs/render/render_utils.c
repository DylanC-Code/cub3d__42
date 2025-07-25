/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:48:05 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 21:52:06 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_game *game, t_image *image, int width, int height)
{
	image->img = mlx_new_image(game->mlx, width, height);
	if (!image->img)
		exit_error("mlx_new_image failed", game);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_len,
			&image->endian);
	if (!image->addr)
		exit_error("mlx_get_data_addr failed", game);
	image->width = width;
	image->height = height;
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

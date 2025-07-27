/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:48:05 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 10:42:28 by dcastor          ###   ########.fr       */
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
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_line(t_image *img, int coordinates[2], int line_len, int color)
{
	int	x;

	x = 0;
	while (coordinates[0] + x < line_len)
	{
		put_pixel(img, coordinates[0] + x, coordinates[1], color);
		x++;
	}
}

void	put_square(t_image *img, int coordinates[2], int line_len, int color)
{
	int	y;
	int	x;

	y = 0;
	while (coordinates[1] + y < coordinates[1] + line_len)
	{
		x = 0;
		while (coordinates[0] + x < coordinates[0] + line_len)
		{
			put_pixel(img, coordinates[0] + x, coordinates[1] + y, color);
			x++;
		}
		y++;
	}
}

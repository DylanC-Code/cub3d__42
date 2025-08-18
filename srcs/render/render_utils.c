/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:48:05 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 10:26:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	abs_val(int x)
// {
// 	return (x < 0 ? -x : x);
// }

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

void	put_pixel(t_image *img, t_coordinates *pos, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = (int)pos->x;
	y = (int)pos->y;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	put_line(t_image *img, t_coordinates *start, t_coordinates *end,
		int color)
{
	t_coordinates	delta;
	t_coordinates	cur_pos;
	t_coordinates	pos_inc;
	int				i;
	int				steps;

	delta.x = end->x - start->x;
	delta.y = end->y - start->y;
	if (fabsf(delta.x) > fabsf(delta.y))
		steps = fabsf(delta.x);
	else
		steps = fabsf(delta.y);
	pos_inc.x = delta.x / steps;
	pos_inc.y = delta.y / steps;
	cur_pos.x = start->x;
	cur_pos.y = start->y;
	i = 0;
	while (i <= steps)
	{
		put_pixel(img, &cur_pos, color);
		cur_pos.x += pos_inc.x;
		cur_pos.y += pos_inc.y;
		i++;
	}
}

void	put_square(t_image *image, t_coordinates *start, int size, int color)
{
	t_coordinates	curr;
	t_coordinates	curr_off;

	curr.y = 0;
	while (start->y + curr.y < start->y + size)
	{
		curr.x = 0;
		while (start->x + curr.x < start->x + size)
		{
			curr_off.x = start->x + curr.x;
			curr_off.y = start->y + curr.y;
			put_pixel(image, &curr_off, color);
			curr.x++;
		}
		curr.y++;
	}
}

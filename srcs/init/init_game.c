/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:55:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 22:00:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	set_background_color(t_game *game, int color)
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// 	char	*dst;

// 	int y, x;
// 	img = mlx_new_image(game->mlx, game->screen_width, game->screen_height);
// 	if (!img)
// 	{
// 		ft_error("set background color");
// 		exit(5);
// 	}
// 	addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
// 	y = -1;
// 	while (++y < game->screen_height)
// 	{
// 		x = -1;
// 		while (++x < game->screen_width)
// 		{
// 			dst = addr + (y * line_len + x * (bpp / 8));
// 			*(unsigned int *)dst = color;
// 		}
// 	}
// 	mlx_put_image_to_window(game->mlx, game->window, img, 0, 0);
// }

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("mlx_init", game);
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	game->window = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3d");
	if (!game->window)
		exit_error("mlx_init", game);
	set_background_color(game, 0x0000FFFF);
}

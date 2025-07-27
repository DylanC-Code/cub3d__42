/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:52:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:54:10 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RENDER_H__
# define __RENDER_H__

# include "cub3d.h"

enum	ELEMENTS
{
	EMPTY,
	WALL,
};

int		render_frame(void *param);
void	display_hud(t_game *game);
// t_status	display_game(t_game *game);
int		display_game(t_game *game);

void	render_map(t_game *game);
void	render_player(t_game *game);

void	create_image(t_game *game, t_image *image, int width, int height);
void	fill_image(t_image *img, int color);
void	set_background_color(t_game *game, int color);

void	put_pixel(t_image *img, int x, int y, int color);
void	put_line(t_image *img, int coordinates[2], int line_len, int color);
void	put_square(t_image *img, int coordinates[2], int line_len, int color);

#endif

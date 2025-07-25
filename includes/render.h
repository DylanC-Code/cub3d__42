/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:52:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 22:58:08 by dcastor          ###   ########.fr       */
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

void	render_map(t_game *game);

void	create_image(t_game *game, t_image *image, int width, int height);
void	set_background_color(t_game *game, int color);

void	put_pixel(t_image *img, int x, int y, int color);
void	put_line(t_image *img, int coordinates[2], int line_len, int color);
void	put_scare(t_image *img, int coordinates[2], int line_len, int color);

#endif

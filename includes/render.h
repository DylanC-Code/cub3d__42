/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:52:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 11:37:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RENDER_H__
# define __RENDER_H__

# include "cub3d.h"

enum				ELEMENTS
{
	EMPTY = '0',
	WALL = '1',
};

void				display_hud(t_game *game);
int					display_game(t_game *game);

void				render_map(t_game *game);
void				render_player(t_game *game);

void				create_image(t_game *game, t_image *image, int width,
						int height);
void				fill_image(t_image *img, int color);
void				set_background_color(t_game *game, int color);

void				put_pixel(t_image *img, t_coordinates *pos, int color);
void				put_line(t_image *img, t_coordinates *start,
						t_coordinates *end, int color);
void				put_square(t_image *img, t_coordinates *pos, int size,
						int color);

unsigned int		get_texel(t_image *tex, int tx, int ty);
t_image				*pick_wall_tex(t_scene *sc, t_side side);
float				wall_u(t_raycaster *ray);
void				render_wall_column(t_game *g, int ray_idx,
						t_raycaster *ray);
void				draw_vspan_color(t_game *g, t_coordinates *start,
						t_coordinates *end, int color);

typedef struct s_draw_wctx
{
	t_game			*game;
	t_image			*tex;
	t_raycaster		*ray;
	int				top;
	int				bot;
	int				x;
	float			shade;
}					t_draw_wctx;

typedef struct s_fill_ctx
{
	t_game			*game;
	int				x;
	int				y0;
	int				y1;
	unsigned int	color;
}					t_fill_ctx;

unsigned int		get_shaded_texel(unsigned int texel, float shade);
float				proj_distance(int screen_w);
void				set_bounds(t_rcol *rc, t_game *g);
float				compute_shade(float dist, int side);

#endif

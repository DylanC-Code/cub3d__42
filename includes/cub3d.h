/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:45:45 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 11:37:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H__
# define __CUB3D_H__

# define PI 3.1415926535
# define MOVE_SPEED 0.05f
# define TILE_SIZE 32
# define FOV (PI / 3) // 60deg
# define RAY_COUNT 60

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct s_textures
{
	char			*east;
	char			*west;
	char			*north;
	char			*south;
	int				floor_color;
	int				ceil_color;
}					t_textures;

typedef struct s_rcol
{
	int				x;
	int				top;
	int				bot;
	int				top_raw;
	int				wall_h;
	float			dist;
	float			proj;
	float			shade;
}					t_rcol;

typedef struct s_wdraw
{
	int				x;
	int				top;
	int				bot;
	int				tx;
	float			v;
	float			vstep;
	float			shade;
}					t_wdraw;

typedef struct s_wall_params
{
	int				top;
	int				bot;
	int				x0;
	int				x1;
	int				tx;
	float			v0;
	float			vstep;
	float			shade;
}					t_wall_params;

typedef struct s_walls_img
{
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			west;
}					t_walls_img;

typedef struct s_scene
{
	t_textures		textures;
	t_walls_img		walls;
	char			*map;
	int				map_width;
	int				map_height;
}					t_scene;

typedef struct s_coordinates
{
	float			x;
	float			y;
}					t_coordinates;

typedef struct s_player
{
	t_coordinates	pos;
	t_coordinates	delta;
	float			angle;
}					t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_image			render;
	t_image			render_hud;
	int				screen_height;
	int				screen_width;
	t_player		player;
	t_scene			scene;
}					t_game;

# include "cleanup.h"
# include "events.h"
# include "init.h"
# include "libft.h"
# include "mlx.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

#endif

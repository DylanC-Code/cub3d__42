/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:45:45 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/28 14:33:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H__
# define __CUB3D_H__

# define PI 3.1415926535
# define MOVE_SPEED 0.05f

typedef struct s_textures
{
	char			*east;
	char			*west;
	char			*north;
	char			*south;
	int				floor_color;
	int				ceil_color;
	int				floor_set;
	int				ceil_set;
}					t_textures;

typedef struct s_scene
{
	t_textures		*textures;
	char			**map;
	int				map_width;
	int				map_height;
}					t_scene;

typedef struct s_coordinates
{
	float			x;
	float			y;
}					t_coordinates;

typedef struct s_ray_hit
{
	t_coordinates	pos;
	float			distance;
	int				is_vertical;
}					t_ray_hit;

typedef struct s_raycaster
{
	t_coordinates	origin;
	float			angle;
	t_ray_hit		hit;
}					t_raycaster;

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
	int				screen_height;
	int				screen_width;
	t_player		player;
	t_scene			scene;
}					t_game;

# include "events.h"
# include "init.h"
# include "libft.h"
# include "mlx.h"
# include "render.h"
# include "parsing.h"
# include "utils.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

#endif

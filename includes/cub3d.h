/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:45:45 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 21:53:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H__
# define __CUB3D_H__

typedef struct s_textures
{
	char		*east;
	char		*west;
	char		*north;
	char		*south;
	int			floor_color;
	int			ceil_color;
}				t_textures;

typedef struct s_scene
{
	t_textures	textures;
	char		**map;
	int			map_width;
	int			map_height;
}				t_scene;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			screen_height;
	int			screen_width;
}				t_game;

# include "init.h"
# include "libft.h"
# include "mlx.h"
# include "render.h"
# include "utils.h"
# include <stdio.h>
# include <unistd.h>

#endif

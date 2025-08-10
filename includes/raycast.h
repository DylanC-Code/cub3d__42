/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:38:06 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 10:37:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAYCAST_H__
# define __RAYCAST_H__

# include "cub3d.h"

typedef enum e_side
{
	SIDE_NORTH,
	SIDE_SOUTH,
	SIDE_EAST,
	SIDE_WEST
}								t_side;

typedef struct s_coordinates	t_coordinates;

typedef struct s_ray_hit
{
	t_coordinates				pos;
	float						distance;
	t_side						side;
	int							is_vertical;
}								t_ray_hit;

typedef struct s_raycaster
{
	t_coordinates				origin;
	float						angle;
	t_ray_hit					hit;
}								t_raycaster;

void							launch_rays(t_game *game);
void							cast_single_ray(t_game *game, t_raycaster *ray);

t_ray_hit						vertical_hit(t_game *game, t_raycaster *ray);
t_ray_hit						horizontal_hit(t_game *game, t_raycaster *ray);
t_coordinates					vector_add(t_coordinates a, t_coordinates b);
float							get_distance(t_coordinates *from,
									t_coordinates *to);
float							correct_fisheye(float dist, float player_angle,
									float ray_angle);

#endif

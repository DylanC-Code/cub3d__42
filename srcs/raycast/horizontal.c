/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:07:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/09 11:36:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_coordinates	get_first_horizontal(t_raycaster *ray,
		t_coordinates *step)
{
	t_coordinates	pos;
	float			tan_a;

	tan_a = tanf(ray->angle);
	if (fabsf(tan_a) < 0.0001f)
		tan_a = 0.0001f;
	if (sin(ray->angle) < 0)
	{
		pos.y = ((int)(ray->origin.y / TILE_SIZE)) * TILE_SIZE - 0.0001f;
		pos.x = (pos.y - ray->origin.y) / tan_a + ray->origin.x;
		step->y = -TILE_SIZE;
		step->x = -TILE_SIZE / tan_a;
	}
	else
	{
		pos.y = ((int)(ray->origin.y / TILE_SIZE)) * TILE_SIZE + TILE_SIZE;
		pos.x = (pos.y - ray->origin.y) / tan_a + ray->origin.x;
		step->y = TILE_SIZE;
		step->x = TILE_SIZE / tan_a;
	}
	return (pos);
}

t_ray_hit	horizontal_hit(t_game *game, t_raycaster *ray)
{
	t_coordinates	pos;
	t_coordinates	step;
	int				depth;
	t_ray_hit		hit;
	t_coordinates	map;

	depth = 0;
	pos = get_first_horizontal(ray, &step);
	while (depth < 100)
	{
		map.x = (int)(pos.x) / TILE_SIZE;
		map.y = (int)(pos.y) / TILE_SIZE;
		if (map.x >= 0 && map.y >= 0 && map.y < game->scene.map_height
			&& map.x < game->scene.map_width && game->scene.map[(int)map.y
			* game->scene.map_width + (int)map.x] == WALL)
		{
			hit.pos = pos;
			hit.distance = get_distance(&ray->origin, &pos);
			return (hit);
		}
		pos = vector_add(pos, step);
		depth++;
	}
	hit.pos = pos;
	hit.distance = 100000;
	return (hit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:33:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/28 17:23:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	is_facing_right(float angle)
// {
// 	return (cos(angle) > 0);
// }

static t_coordinates	get_first_vertical(t_raycaster *ray,
	t_coordinates *step)
{
	t_coordinates	pos;
	float			tan_a;

	// Si l'angle est proche de la verticale, on met un tan énorme
	if (fabsf(cosf(ray->angle)) < 0.0001f)
		tan_a = 1000000.0f;
	else
		tan_a = tanf(ray->angle);

	if (cosf(ray->angle) > 0) // vers la droite
	{
		pos.x = (((int)ray->origin.x >> 5) << 5) + TILE_SIZE;
		pos.y = (pos.x - ray->origin.x) * tan_a + ray->origin.y;
		step->x = TILE_SIZE;
		step->y = TILE_SIZE * tan_a;
	}
	else // vers la gauche
	{
		pos.x = (((int)ray->origin.x >> 5) << 5) - 0.0001f;
		pos.y = (pos.x - ray->origin.x) * tan_a + ray->origin.y;
		step->x = -TILE_SIZE;
		step->y = TILE_SIZE * tan_a * -1;
	}
	return (pos);
}


t_ray_hit	vertical_hit(t_game *game, t_raycaster *ray)
{
	t_coordinates	pos;
	t_coordinates	step;
	int				depth;
	t_ray_hit		hit;
	t_coordinates	map;

	depth = 0;
	pos = get_first_vertical(ray, &step);
	while (depth < 8)
	{
		map.x = (int)(pos.x) >> 5;
		map.y = (int)(pos.y) >> 5;
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

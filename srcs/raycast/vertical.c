/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:33:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 14:07:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_coordinates	get_first_vertical(t_raycaster *ray,
		t_coordinates *step)
{
	t_coordinates	pos;
	float			tan_a;

	if (fabsf(cosf(ray->angle)) < 0.0001f)
		tan_a = 1000000.0f;
	else
		tan_a = tanf(ray->angle);
	if (cosf(ray->angle) > 0)
	{
		pos.x = (((int)ray->origin.x >> 5) << 5) + TILE_SIZE;
		pos.y = (pos.x - ray->origin.x) * tan_a + ray->origin.y;
		step->x = TILE_SIZE;
		step->y = TILE_SIZE * tan_a;
	}
	else
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
	int				depth;
	t_ray_hit		hit;
	t_coordinates	map;
	t_coordinates	pos;
	t_coordinates	step;

	depth = 0;
	pos = get_first_vertical(ray, &step);
	while (depth < game->screen_width / TILE_SIZE)
	{
		map.x = (int)(pos.x) >> 5;
		map.y = (int)(pos.y) >> 5;
		if (is_in_map(game, map))
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

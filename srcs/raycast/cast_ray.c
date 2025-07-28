/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:58:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/28 17:25:24 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_single_ray(t_game *game, t_raycaster *ray)
{
	t_ray_hit	hit_h;
	t_ray_hit	hit_v;

	hit_h = horizontal_hit(game, ray);
	hit_v = vertical_hit(game, ray);
	if (hit_h.distance < hit_v.distance)
	{
		ray->hit = hit_h;
		ray->hit.is_vertical = 0;
	}
	else
	{
		ray->hit = hit_v;
		ray->hit.is_vertical = 1;
	}
	ray->hit.distance = correct_fisheye(ray->hit.distance, game->player.angle,
			ray->angle);
}

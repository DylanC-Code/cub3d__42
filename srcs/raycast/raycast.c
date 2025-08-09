/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:38:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/09 11:41:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	launch_rays(t_game *game)
{
	int			ray_index;
	float		start_angle;
	float		angle_step;
	t_raycaster	ray;

	angle_step = FOV / (float)RAY_COUNT;
	start_angle = game->player.angle - (FOV / 2.0f);
	ray_index = -1;
	while (++ray_index < RAY_COUNT)
	{
		ray.origin.x = game->player.pos.x * TILE_SIZE + 4;
		ray.origin.y = game->player.pos.y * TILE_SIZE + 4;
		ray.angle = normalize_angle(-(start_angle + ray_index * angle_step));
		cast_single_ray(game, &ray);
		put_line(&game->render, &ray.origin, &ray.hit.pos, 0xFF0000);
	}
}

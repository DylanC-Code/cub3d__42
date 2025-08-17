/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:38:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/17 20:52:11 by dcastor          ###   ########.fr       */
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

void	determine_side(t_ray_hit *hit, float cast_angle)
{
	if (hit->is_vertical)
	{
		if (cosf(cast_angle) > 0.0f)
			hit->side = SIDE_WEST;
		else
			hit->side = SIDE_EAST;
	}
	else
	{
		if (sinf(cast_angle) > 0.0f)
			hit->side = SIDE_SOUTH;
		else
			hit->side = SIDE_NORTH;
	}
}

void	launch_rays(t_game *game)
{
	int			screen_x;
	float		angle_step;
	float		ray_angle;
	t_raycaster	ray;

	angle_step = FOV / (float)game->screen_width;
	screen_x = -1;
	while (++screen_x < game->screen_width)
	{
		ray_angle = game->player.angle + ((screen_x - (game->screen_width
						/ 2.0f)) * angle_step);
		ray.angle = normalize_angle(ray_angle);
		ray.origin.x = game->player.pos.x * TILE_SIZE + 4;
		ray.origin.y = game->player.pos.y * TILE_SIZE + 4;
		cast_single_ray(game, &ray);
		determine_side(&ray.hit, ray.angle);
		render_wall_column(game, screen_x, ray.angle, &ray);
	}
}

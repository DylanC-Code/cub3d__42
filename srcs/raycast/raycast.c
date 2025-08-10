/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:38:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 15:25:34 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

// void	render_wall_column(t_game *game, int screen_x, float cast_angle,
// 		t_raycaster *ray)
// {
// 	t_coordinates	d;
// 	t_image			*tex;
// 	float			u;
// 	int				tx;
// 	float			wall_screen_h;
// 	float			v_step;
// 	int				y_start;
// 	float			v;
// 	float			shade_dist;
// 	float			face_boost;
// 	float			f;
// 	int				ty;
// 	unsigned int	texel;
// 	unsigned int	shaded;
// 	t_coordinates	p;

// 	int r, g, b;
// 	float dist, delta, dist_corr, proj_dist, wall_h;
// 	int top, bot;
// 	d.x = ray->hit.pos.x - ray->origin.x;
// 	d.y = ray->hit.pos.y - ray->origin.y;
// 	dist = sqrtf(d.x * d.x + d.y * d.y);
// 	delta = cast_angle - game->player.angle;
// 	dist_corr = dist * cosf(delta);
// 	if (dist_corr < 0.0001f)
// 		dist_corr = 0.0001f;
// 	proj_dist = (game->screen_width * 0.5f) / tanf(FOV * 0.5f);
// 	wall_h = (TILE_SIZE * proj_dist) / dist_corr;
// 	top = (int)(game->screen_height * 0.5f - wall_h * 0.5f);
// 	bot = (int)(game->screen_height * 0.5f + wall_h * 0.5f);
// 	// Plafond
// 	for (int y = 0; y < top && y < game->screen_height; ++y)
// 	{
// 		p.x = screen_x;
// 		p.y = y;
// 		put_pixel(&game->render, &p, game->scene.textures.ceil_color);
// 	}
// 	// Mur texturé
// 	tex = pick_wall_tex(&game->scene, ray->hit.side);
// 	u = wall_u(ray) * (float)(tex->width - 1);
// 	tx = (int)u;
// 	wall_screen_h = (float)(bot - top + 1);
// 	v_step = (float)tex->height / wall_screen_h;
// 	y_start = top < 0 ? 0 : top;
// 	v = (top < 0) ? (-top) * v_step : 0.0f;
// 	shade_dist = dist_corr / 900.0f;
// 	if (shade_dist > 0.7f)
// 		shade_dist = 0.7f;
// 	face_boost = (ray->hit.side == SIDE_EAST
// 			|| ray->hit.side == SIDE_WEST) ? 0.08f : 0.0f;
// 	f = shade_dist + face_boost;
// 	if (f > 0.85f)
// 		f = 0.85f;
// 	if (f < 0.0f)
// 		f = 0.0f;
// 	for (int y = y_start; y <= bot && y < game->screen_height; ++y)
// 	{
// 		ty = (int)v;
// 		texel = get_texel(tex, tx, ty);
// 		r = ((texel >> 16) & 0xFF);
// 		r = (int)(r * (1.0f - f));
// 		g = ((texel >> 8) & 0xFF);
// 		g = (int)(g * (1.0f - f));
// 		b = (texel & 0xFF);
// 		b = (int)(b * (1.0f - f));
// 		shaded = (r << 16) | (g << 8) | b;
// 		p.x = screen_x;
// 		p.y = y;
// 		put_pixel(&game->render, &p, shaded);
// 		v += v_step;
// 	}
// 	// Sol
// 	for (int y = bot + 1; y < game->screen_height; ++y)
// 	{
// 		p.x = screen_x;
// 		p.y = y;
// 		put_pixel(&game->render, &p, game->scene.textures.floor_color);
// 	}
// }

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
		determine_side(&ray.hit, ray.angle);
		put_line(&game->render_hud, &ray.origin, &ray.hit.pos, 0xFF0000);
		render_wall_column(game, ray_index, -ray.angle, &ray);
	}
}

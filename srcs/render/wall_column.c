/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 14:47:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compute_params(t_game *g, int idx, float cast, t_raycaster *ray,
		t_image *tex, t_wall_params *o)
{
	t_coordinates	d;
	float			dist;
	float			dist_corr;
	float			proj_dist;
	float			wall_h;
	int				col_w;

	d.x = ray->hit.pos.x - ray->origin.x;
	d.y = ray->hit.pos.y - ray->origin.y;
	dist = sqrtf(d.x * d.x + d.y * d.y);
	dist_corr = dist * cosf(cast - g->player.angle);
	if (dist_corr < 0.0001f)
		dist_corr = 0.0001f;
	proj_dist = (g->screen_width * 0.5f) / tanf(FOV * 0.5f);
	wall_h = (TILE_SIZE * proj_dist) / dist_corr;
	o->top = (int)(g->screen_height * 0.5f - wall_h * 0.5f);
	o->bot = (int)(g->screen_height * 0.5f + wall_h * 0.5f);
	col_w = (g->screen_width + RAY_COUNT - 1) / RAY_COUNT;
	o->x0 = idx * col_w;
	o->x1 = o->x0 + col_w - 1;
	if (o->x1 >= g->screen_width)
		o->x1 = g->screen_width - 1;
	o->tx = (int)(wall_u(ray) * (float)(tex->width - 1));
	o->vstep = (float)tex->height / (float)(o->bot - o->top + 1);
	o->v0 = (o->top < 0) ? (-o->top) * o->vstep : 0.0f;
	o->shade = dist_corr / 900.0f;
	if (o->shade > 0.7f)
		o->shade = 0.7f;
	if (ray->hit.side == SIDE_EAST || ray->hit.side == SIDE_WEST)
		o->shade += 0.08f;
}

void	render_wall_column(t_game *game, int screen_x, float cast_angle,
        t_raycaster *ray)
{
    t_image			*tex;
    t_wall_params	w;

    tex = pick_wall_tex(&game->scene, ray->hit.side);
    compute_params(game, 0, cast_angle, ray, tex, &w); // idx n'est plus utilisé
    w.x0 = w.x1 = screen_x; // On dessine une seule colonne
    if (w.top > 0)
        draw_vspan_color(game, screen_x, screen_x, 0, w.top - 1,
            game->scene.textures.ceil_color);
    draw_textured_span(game, tex, screen_x, screen_x, w.top, w.bot, w.tx, w.v0, w.vstep,
        w.shade);
    if (w.bot < game->screen_height - 1)
        draw_vspan_color(game, screen_x, screen_x, w.bot + 1, game->screen_height - 1,
            game->scene.textures.floor_color);
}

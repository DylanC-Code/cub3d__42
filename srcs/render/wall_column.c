/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 11:38:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceil(t_game *g, t_rcol *rc)
{
	t_coordinates	s;
	t_coordinates	e;

	if (rc->top <= 0)
		return ;
	s.x = rc->x;
	s.y = 0;
	e.x = rc->x + 1;
	e.y = rc->top - 1;
	draw_vspan_color(g, &s, &e, g->scene.textures.ceil_color);
}

static void	draw_floor(t_game *g, t_rcol *rc)
{
	t_coordinates	s;
	t_coordinates	e;

	if (rc->bot >= g->screen_height - 1)
		return ;
	s.x = rc->x;
	s.y = rc->bot + 1;
	e.x = rc->x + 1;
	e.y = g->screen_height - 1;
	draw_vspan_color(g, &s, &e, g->scene.textures.floor_color);
}

static void	wall_setup(t_wdraw *wd, t_image *tex, t_raycaster *ray, t_rcol *rc)
{
	float	u;
	int		w;

	w = tex->width - 1;
	u = wall_u(ray);
	wd->tx = (int)(u * (float)w);
	if (wd->tx < 0)
		wd->tx = 0;
	if (wd->tx > w)
		wd->tx = w;
	wd->vstep = (float)tex->height / (float)(rc->wall_h);
	wd->v = (float)(rc->top - rc->top_raw) * wd->vstep;
}

static void	wall_draw_span(t_game *g, t_image *t, t_wdraw *wd)
{
	int				y;
	int				ty;
	unsigned int	texel;
	unsigned int	shaded;
	t_coordinates	p;

	y = wd->top;
	p.x = wd->x;
	while (y <= wd->bot)
	{
		ty = (int)wd->v;
		texel = get_texel(t, wd->tx, ty);
		shaded = get_shaded_texel(texel, wd->shade);
		p.y = y;
		put_pixel(&g->render, &p, shaded);
		wd->v += wd->vstep;
		y++;
	}
}

void	render_wall_column(t_game *g, int ray_index, t_raycaster *ray)
{
	t_rcol	rc;
	t_image	*tex;
	t_wdraw	wd;

	if (ray_index < 0 || ray_index >= g->screen_width)
		return ;
	rc.x = ray_index;
	rc.dist = ray->hit.distance;
	if (rc.dist < 0.0001f)
		rc.dist = 0.0001f;
	rc.proj = proj_distance(g->screen_width);
	set_bounds(&rc, g);
	draw_ceil(g, &rc);
	tex = pick_wall_tex(&g->scene, ray->hit.side);
	if (tex)
	{
		rc.shade = compute_shade(rc.dist, ray->hit.side);
		wd.x = rc.x;
		wd.top = rc.top;
		wd.bot = rc.bot;
		wd.shade = rc.shade;
		wall_setup(&wd, tex, ray, &rc);
		wall_draw_span(g, tex, &wd);
	}
	draw_floor(g, &rc);
}

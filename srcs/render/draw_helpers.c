/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:18 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 14:27:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vspan_color(t_game *g, int x0, int x1, int y0, int y1, int color)
{
	t_coordinates	p;

	if (y0 < 0)
		y0 = 0;
	if (y1 >= g->screen_height)
		y1 = g->screen_height - 1;
	for (int x = x0; x <= x1; ++x)
	{
		p.x = x;
		for (int y = y0; y <= y1; ++y)
		{
			p.y = y;
			put_pixel(&g->render, &p, color);
		}
	}
}

static unsigned int	apply_shade(unsigned int c, float f)
{
	int	r;
	int	g;
	int	b;

	if (f < 0.0f)
		f = 0.0f;
	if (f > 0.85f)
		f = 0.85f;
	r = (int)(((c >> 16) & 0xFF) * (1.0f - f));
	g = (int)(((c >> 8) & 0xFF) * (1.0f - f));
	b = (int)((c & 0xFF) * (1.0f - f));
	return ((r << 16) | (g << 8) | b);
}

void	draw_textured_span(t_game *g, t_image *tex, int x0, int x1, int y0,
		int y1, int tx, float v0, float vstep, float shade)
{
	t_coordinates	p;
	float			v;
	int				ty;
	unsigned int	texel;

	if (y0 < 0)
	{
		v0 += (-y0) * vstep;
		y0 = 0;
	}
	if (y1 >= g->screen_height)
		y1 = g->screen_height - 1;
	if (x1 >= g->screen_width)
		x1 = g->screen_width - 1;
	if (x0 < 0)
		x0 = 0;
	v = v0;
	for (int y = y0; y <= y1; ++y)
	{
		ty = (int)v;
		texel = get_texel(tex, tx, ty);
		texel = apply_shade(texel, shade);
		for (int x = x0; x <= x1; ++x)
		{
			p.x = x;
			p.y = y;
			put_pixel(&g->render, &p, (int)texel);
		}
		v += vstep;
	}
}

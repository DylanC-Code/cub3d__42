/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:53:35 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 14:27:05 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_texel(t_image *tex, int tx, int ty)
{
	char	*p;

	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	if (ty >= tex->height)
		ty = tex->height - 1;
	p = tex->addr + (ty * tex->line_len + tx * (tex->bpp / 8));
	return (*(unsigned int *)p);
}

t_image	*pick_wall_tex(t_scene *sc, t_side side)
{
	if (side == SIDE_NORTH)
		return (&sc->walls.north);
	if (side == SIDE_SOUTH)
		return (&sc->walls.south);
	if (side == SIDE_EAST)
		return (&sc->walls.east);
	return (&sc->walls.west);
}

float	wall_u(t_raycaster *ray)
{
	float	u;

	if (ray->hit.is_vertical)
	{
		u = fmodf(ray->hit.pos.y, 64) / (float)64;
		if (cosf(-ray->angle) < 0)
			u = 1.0f - u;
	}
	else
	{
		u = fmodf(ray->hit.pos.x, 64) / (float)64;
		if (sinf(-ray->angle) < 0)
			u = 1.0f - u;
	}
	if (u < 0)
		u += 1.0f;
	if (u >= 1.0f)
		u -= 1.0f;
	return (u);
}

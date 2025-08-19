/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_column_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:36:45 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 11:37:42 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	proj_distance(int screen_w)
{
	float	p;

	p = (float)screen_w * 0.5f;
	p = p / tanf(FOV * 0.5f);
	return (p);
}

void	set_bounds(t_rcol *rc, t_game *g)
{
	int	mid;
	int	b;

	rc->wall_h = (int)(((float)TILE_SIZE * rc->proj) / rc->dist);
	mid = g->screen_height / 2;
	rc->top_raw = mid - (rc->wall_h / 2);
	b = rc->top_raw + rc->wall_h - 1;
	rc->top = rc->top_raw;
	if (rc->top < 0)
		rc->top = 0;
	rc->bot = b;
	if (rc->bot >= g->screen_height)
		rc->bot = g->screen_height - 1;
}

float	compute_shade(float dist, int side)
{
	float	s;

	s = dist / (TILE_SIZE * 8.0f);
	if (side == SIDE_EAST || side == SIDE_WEST)
		s = s + 0.08f;
	if (s > 0.85f)
		s = 0.85f;
	if (s < 0.0f)
		s = 0.0f;
	return (s);
}

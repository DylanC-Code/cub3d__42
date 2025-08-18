/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:18 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 10:29:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vspan_color(t_game *g, t_coordinates *start, t_coordinates *end,
		int color)
{
	t_coordinates	p;
	t_coordinates	p2;

	if (start->y < 0)
		start->y = 0;
	if (end->y >= g->screen_height)
		end->y = g->screen_height - 1;
	p2.x = start->x;
	while (p2.x < end->x)
	{
		p.x = p2.x;
		p2.y = start->y;
		while (p2.y <= end->y)
		{
			p.y = p2.y;
			put_pixel(&g->render, &p, color);
			p2.y++;
		}
		p2.x++;
	}
}

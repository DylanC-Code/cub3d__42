/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:06:45 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 10:07:31 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_player_pos(t_game*g)
{
	char *pos=ft_str_contains_any(g->scene.map, "SWEN");
	g->player.pos.x = (pos - g->scene.map) % (g->scene.map_width + WIDTH_PADDING);
	g->player.pos.y = (pos - g->scene.map) / (g->scene.map_height + HEIGHT_PADDING);
	printf("%f\n", g->player.pos.x);
}
void	init_player(t_game *g)
{
	g->player.delta.x = cos(g->player.angle) * MOVE_SPEED;
	g->player.delta.y = -sin(g->player.angle) * MOVE_SPEED;
	set_player_angle(
g,
		*ft_str_contains_any(g->scene.map, "SWEN")
	);
	set_player_pos(g);
}

/*
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111100111111111111111111111000011111111111111111100E000111111111111111111110011101111111111111111111100001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
*/
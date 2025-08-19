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

void	init_player(t_game *g)
{
	g->player.delta.x = cos(g->player.angle) * MOVE_SPEED;
	g->player.delta.y = -sin(g->player.angle) * MOVE_SPEED;
}

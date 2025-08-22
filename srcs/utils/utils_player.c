/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:46:31 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:22:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_angle(t_game *g, char c)
{
	if (c == 'N')
		g->player.angle = -(PI / 2);
	else if (c == 'S')
		g->player.angle = PI / 2;
	else if (c == 'W')
		g->player.angle = PI;
	else if (c == 'E')
		g->player.angle = 0;
}

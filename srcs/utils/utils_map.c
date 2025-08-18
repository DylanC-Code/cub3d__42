/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:09:10 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 10:11:20 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_map(t_game *game, t_coordinates map)
{
	return (map.x >= 0 && map.y >= 0 && map.y < game->scene.map_height
		&& map.x < game->scene.map_width && game->scene.map[(int)map.y
			* game->scene.map_width + (int)map.x] == WALL);
}

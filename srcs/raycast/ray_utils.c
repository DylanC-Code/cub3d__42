/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:12:34 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/28 16:55:20 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_distance(t_coordinates *from, t_coordinates *to)
{
	float	dx;
	float	dy;

	dx = to->x - from->x;
	dy = to->y - from->y;
	return (sqrtf(dx * dx + dy * dy));
}

float	correct_fisheye(float dist, float player_angle, float ray_angle)
{
	float	diff;

	diff = ray_angle - player_angle;
	while (diff < -PI)
		diff += 2 * PI;
	while (diff > PI)
		diff -= 2 * PI;
	return (dist * cosf(diff));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/28 16:12:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coordinates	vector_add(t_coordinates a, t_coordinates b)
{
	t_coordinates	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return (v);
}

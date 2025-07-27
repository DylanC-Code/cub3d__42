/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:05:28 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:13:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_events(t_game *game)
{
	mlx_hook(game->window, DestroyNotify, 0, &exit_game, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &inputs_handlers, game);
}

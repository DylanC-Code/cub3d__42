/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:23:25 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/09 14:30:02 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_game(t_game *game)
{
	display_hud(game);
	launch_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->render.img, 0, 0);
	 mlx_put_image_to_window(game->mlx, game->window, game->render_hud.img, 0,
		0);
	return (SUCCESS);
}

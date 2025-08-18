/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:11:30 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 14:27:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_status	inputs_handlers(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		return (exit_game(game));
	else if (key_code == KEY_W)
		move_up(game);
	else if (key_code == KEY_D)
		move_right(game);
	else if (key_code == KEY_A)
		move_left(game);
	else if (key_code == KEY_S)
		move_down(game);
	return (SUCCESS);
}

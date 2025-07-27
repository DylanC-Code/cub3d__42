/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:07:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 11:21:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EVENTS_H__
# define __EVENTS_H__

# include "cub3d.h"
# include "libft.h"

typedef enum KEYS
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307
}			t_keys;

void		handle_events(t_game *game);
t_status	exit_game(t_game *game);
t_status	inputs_handlers(int key_code, t_game *game);

void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);

#endif

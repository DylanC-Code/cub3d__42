/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:12:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 10:08:05 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INIT_H__
# define __INIT_H__

void	init_game(t_game *game);
void	check_args(int argc, char **argv);
void	load_walls_textures(t_game *g);
void	init_player(t_game *g);

#endif

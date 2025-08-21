/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:01:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 09:55:12 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_H__
# define __UTILS_H__

void	ft_error(char *msg);
void	exit_error(char *msg, t_game *game);
char	*map_to_string(char **map);
void clear_map(char *map);

int		is_in_map(t_game *game, t_coordinates map);
void	set_player_angle(t_game *g, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:01:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 21:50:52 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_H__
# define __UTILS_H__

void	ft_error(char *msg);
void	exit_error(char *msg, t_game *game);
char	*map_to_string(char **map);

#endif

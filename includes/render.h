/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:52:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 21:57:51 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RENDER_H__
# define __RENDER_H__

# include "cub3d.h"

void	create_image(t_game *game, t_image *image, int width, int height);
void	put_pixel(t_image *img, int x, int y, int color);
void	set_background_color(t_game *game, int color);

#endif

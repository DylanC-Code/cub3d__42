/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:24:28 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/10 11:03:48 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_img(t_game *g, t_image *im)
{
	if (!im || !im->img)
		return ;
	mlx_destroy_image(g->mlx, im->img);
	im->img = NULL;
	im->addr = NULL;
}

static void	destroy_wall_images(t_game *g)
{
	destroy_img(g, &g->scene.walls.north);
	destroy_img(g, &g->scene.walls.south);
	destroy_img(g, &g->scene.walls.east);
	destroy_img(g, &g->scene.walls.west);
}

static void	free_scene_data(t_scene *s)
{
	if (!s)
		return ;
	free(s->textures.north);
	free(s->textures.south);
	free(s->textures.east);
	free(s->textures.west);
	s->textures.north = NULL;
	s->textures.south = NULL;
	s->textures.east = NULL;
	s->textures.west = NULL;
	// free(s->map);
	s->map = NULL;
}

int	free_and_exit(t_game *g, int code)
{
	if (g)
	{
		destroy_img(g, &g->render);
		destroy_img(g, &g->render_hud);
		destroy_wall_images(g);
		free_scene_data(&g->scene);
		if (g->window)
			mlx_destroy_window(g->mlx, g->window);
		if (g->mlx)
			mlx_destroy_display(g->mlx);
		g->mlx = NULL;
	}
	exit(code);
	return (code);
}

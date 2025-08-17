/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/17 20:55:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_wall_column(t_game *game, int ray_index, float cast_angle,
        t_raycaster *ray)
{
    t_image		*tex;
    int			screen_x;
    float		proj_dist;
    float		dist;
    int			wall_h;
    int			top;
    int			bot;
    int			tx;
    float		vstep;
    float		v;
    unsigned int	texel;
    int			r, g, b;
    unsigned int	shaded;
    t_coordinates	p;
    float		shade;

	(void)cast_angle;
    screen_x = ray_index;
    if (screen_x < 0 || screen_x >= game->screen_width)
        return ;

    dist = ray->hit.distance;
    if (dist < 0.0001f)
        dist = 0.0001f;
    proj_dist = ((float)game->screen_width * 0.5f) / tanf(FOV * 0.5f);
    wall_h = (int)((TILE_SIZE * proj_dist) / dist);

    top = (game->screen_height / 2) - (wall_h / 2);
    bot = top + wall_h - 1;
    if (top < 0)
        top = 0;
    if (bot >= game->screen_height)
        bot = game->screen_height - 1;

    if (top > 0)
        draw_vspan_color(game, screen_x, screen_x, 0, top - 1,
            game->scene.textures.ceil_color);

    tex = pick_wall_tex(&game->scene, ray->hit.side);
    if (tex)
    {
        tx = (int)(wall_u(ray) * (float)(tex->width - 1));
        if (tx < 0) tx = 0;
        if (tx >= tex->width) tx = tex->width - 1;

        vstep = (float)tex->height / (float)(bot - top + 1);
        v = (top < 0) ? (-top) * vstep : 0.0f;

        shade = dist / (TILE_SIZE * 8.0f);
        if (shade < 0.0f) shade = 0.0f;
        if (shade > 0.85f) shade = 0.85f;
        if (ray->hit.side == SIDE_EAST || ray->hit.side == SIDE_WEST)
            shade += 0.08f;
        if (shade > 0.85f) shade = 0.85f;

        p.x = screen_x;
        for (int y = top; y <= bot; ++y)
        {
            int ty = (int)v;
            texel = get_texel(tex, tx, ty);
            r = (texel >> 16) & 0xFF;
            g = (texel >> 8) & 0xFF;
            b = texel & 0xFF;
            r = (int)(r * (1.0f - shade));
            g = (int)(g * (1.0f - shade));
            b = (int)(b * (1.0f - shade));
            shaded = (r << 16) | (g << 8) | b;
            p.y = y;
            put_pixel(&game->render, &p, shaded);
            v += vstep;
        }
    }
    if (bot < game->screen_height - 1)
        draw_vspan_color(game, screen_x, screen_x, bot + 1, game->screen_height - 1,
            game->scene.textures.floor_color);
}

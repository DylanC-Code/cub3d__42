/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:11:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/18 10:28:39 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_shaded_texel(unsigned int texel, float shade)
{
    int	r;
    int	g;
    int	b;

    if (shade < 0.0f)
        shade = 0.0f;
    if (shade > 0.85f)
        shade = 0.85f;
    r = (int)(((texel >> 16) & 0xFF) * (1.0f - shade));
    g = (int)(((texel >> 8) & 0xFF) * (1.0f - shade));
    b = (int)((texel & 0xFF) * (1.0f - shade));
    return ((r << 16) | (g << 8) | b);
}

static void	draw_wall_tex(t_game *game, t_image *tex, int screen_x,
        t_raycaster *ray, int top, int bot, float shade)
{
    int				tx;
    float			vstep;
    float			v;
    int				y;
    int				ty;
    unsigned int	texel;
    unsigned int	shaded;
    t_coordinates	p;

    tx = (int)(wall_u(ray) * (float)(tex->width - 1));
    if (tx < 0)
        tx = 0;
    if (tx >= tex->width)
        tx = tex->width - 1;
    vstep = (float)tex->height / (float)(bot - top + 1);
    v = (top < 0) ? (-top) * vstep : 0.0f;
    p.x = screen_x;
    y = top;
    while (y <= bot)
    {
        ty = (int)v;
        texel = get_texel(tex, tx, ty);
        shaded = get_shaded_texel(texel, shade);
        p.y = y;
        put_pixel(&game->render, &p, shaded);
        v += vstep;
        y++;
    }
}

void	render_wall_column(t_game *game, int ray_index, float cast_angle,
        t_raycaster *ray)
{
    t_image	*tex;
    int		screen_x;
    float	proj_dist;
    float	dist;
    int		wall_h;
    int		top;
    int		bot;
    float	shade;

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
    {
        t_coordinates s;
        t_coordinates e;
        s.x = screen_x;
        s.y = 0;
        e.x = screen_x + 1;
        e.y = top - 1;
        draw_vspan_color(game, &s, &e, game->scene.textures.ceil_color);
    }
    tex = pick_wall_tex(&game->scene, ray->hit.side);
    if (tex)
    {
        shade = dist / (TILE_SIZE * 8.0f);
        if (ray->hit.side == SIDE_EAST || ray->hit.side == SIDE_WEST)
            shade += 0.08f;
        if (shade > 0.85f)
            shade = 0.85f;
        draw_wall_tex(game, tex, screen_x, ray, top, bot, shade);
    }
    if (bot < game->screen_height - 1)
    {
        t_coordinates s;
        t_coordinates e;
        s.x = screen_x;
        s.y = bot + 1;
        e.x = screen_x + 1;
        e.y = game->screen_height - 1;
        draw_vspan_color(game, &s, &e, game->scene.textures.floor_color);
    }
}

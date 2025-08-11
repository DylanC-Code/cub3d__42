/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:24 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/27 15:33:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 'N', 0, 0, 0, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1,
};

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	ft_bzero(&game, sizeof(t_game));
	// game.scene.map = (char *)map;
	// game.scene.map_height = 10;
	// game.scene.map_width = 10;
	// game.player.pos.x = 5;
	// game.player.pos.y = 5;
	// game.player.angle = PI / 2;
	// game.player.delta.x = cos(game.player.angle) * MOVE_SPEED;
	// game.player.delta.y = -sin(game.player.angle) * MOVE_SPEED;
	// // init_map(argc, argv);
	// init_game(&game);
	// // check_args(argc, argv);
	// handle_events(&game);
	// // mlx_loop_hook(game.mlx, render_frame, &game);
	// mlx_loop_hook(game.mlx, display_game, &game);
	// mlx_loop(game.mlx);
	check_map(argv[1]);
	return (EXIT_SUCCESS);
	
}

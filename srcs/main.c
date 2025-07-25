/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:24 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 22:42:45 by dcastor          ###   ########.fr       */
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
	game.scene.map = (char *)map;
	game.scene.map_height = 10;
	game.scene.map_width = 10;
	// init_map(argc, argv);
	init_game(&game);
	render_map(&game);
	// check_args(argc, argv);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

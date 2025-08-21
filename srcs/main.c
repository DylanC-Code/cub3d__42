/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:24 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/19 10:07:35 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map[] = {
	'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0',
		'0', '0', '0', '0', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0',
		'1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', 'N', '0', '0', '0', '1', '1', '0',
		'0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1',
		'1', '1', '1', '1',
};

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		exit_error("Map missing!",&game);
	if(!check_map( argv[1],&game.scene))
	free_and_exit( &game,2);
	init_game(&game);
	handle_events(&game);
	mlx_loop_hook(game.mlx, display_game, &game);
	mlx_loop(game.mlx);
	return (exit_game(&game));
	// if(scene)
	// {
	// 	for(int i = 0; scene->map[i] ; i++)
	// 		printf("map[%d]: %s\n", i, scene->map[i]);
	// 	char *map = map_to_string(scene->map);
	// 	if (map)
	// 	{
	// 		printf("[H: %d] [W: %d]\n char* map:\n%s\n", scene->map_height, scene->map_width, map);
	// 		free(map);
	// 	}
	// }
	// free_scene(scene);
	//printf("Scene map: %p\n", scene);
	return (EXIT_SUCCESS);
	
}

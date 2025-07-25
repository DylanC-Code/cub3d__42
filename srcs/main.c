/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:24 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 10:57:18 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("wrong number of arguments");
		printf("./cub3d <*.cub>\n");
		exit(1);
	}
	if (!ft_ends_with(argv[1], ".cub"))
	{
		ft_error("wrong map extension");
		printf("./cub3d <*.cub>\n");
		exit(2);
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}

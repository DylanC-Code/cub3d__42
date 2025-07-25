/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:12:16 by dcastor           #+#    #+#             */
/*   Updated: 2025/07/25 11:14:09 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("wrong number of arguments");
		printf("Example: ./cub3d <map_file.cub>");
		exit(1);
	}
	if (!ft_ends_with(argv[1], ".cub"))
	{
		ft_error("wrong map extension");
		printf("Example: ./cub3d <map_file.cub>");
		exit(2);
	}
}

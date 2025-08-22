/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:47:03 by saal-kur          #+#    #+#             */
/*   Updated: 2025/08/22 10:12:05 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_statics(int *player_count, int *map_started)
{
	*player_count = 0;
	*map_started = 0;
}

int	parse_map_line(char *line, t_map_data **data)
{
	t_map_data	*elem;
	static int	player_count = 0;
	static int	map_started = 0;

	elem = NULL;
	if (!*data && map_started)
		reset_statics(&player_count, &map_started);
	if (is_empty_line(line))
	{
		if (map_started)
			return (write(2, "Error\nEmpty line in map\n", 24), 0);
		return (1);
	}
	map_started = 1;
	if (!is_valid_line(line))
		return (0);
	if (!check_line(line, &player_count))
		return (0);
	elem = new_elem(line);
	if (!elem)
		return (free_map_data_list(*data), 0);
	ft_map_add_back(data, elem);
	return (1);
}

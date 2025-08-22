/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:10:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:37:03 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_line(char *line, int *player_count)
{
	int	players_in_line;
	int	i;
	int	has_content;

	players_in_line = count_players_in_line(line);
	*player_count += players_in_line;
	if (*player_count > 1)
		return (write(2, "Error\nMultiple player positions\n", 33), 0);
	i = 0;
	has_content = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			has_content = 1;
		i++;
	}
	if (!has_content)
		return (0);
	return (1);
}

int	check_map_content(t_map_data *data)
{
	int	line_count;
	int	has_content;

	line_count = 0;
	has_content = 0;
	while (data)
	{
		line_count++;
		if (data->length > 0)
			has_content = 1;
		data = data->next;
	}
	if (line_count == 0)
		return (write(2, "Error\nNo map found\n", 19), 0);
	if (!has_content)
		return (write(2, "Error\nMap is empty\n", 19), 0);
	return (1);
}

int	validate_map_reqs(t_map_data *data)
{
	int			player_count;
	t_map_data	*temp;

	if (!check_map_content(data))
		return (0);
	player_count = 0;
	temp = data;
	while (temp)
	{
		player_count += count_players_in_line(temp->line);
		temp = temp->next;
	}
	if (player_count == 0)
		return (write(2, "Error\nNo starting player position\n", 35), 0);
	if (player_count > 1)
		return (write(2, "Error\nMultiple starting player positions\n", 33), 0);
	return (1);
}

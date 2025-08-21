/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 12:47:03 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-10 12:47:03 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == '\t' || 
			c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_line(char *line)
{
	char	*ptr;
	int		len;

	ptr = line;
	len = 0;
	while (*ptr && *ptr != '\n')
	{
		if (!is_valid_char(*ptr))
			return (write(2, "Error\nInvalid character in map\n", 32), 0);
		ptr++;
		len++;
	}
	if (len == 0)
		return (0);
	return (len);
}

int	count_players_in_line(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S' || 
			line[i] == 'E' || line[i] == 'W')
			count++;
		i++;
	}
	return (count);
}

t_map_data	*new_elem(char *line)
{
	t_map_data	*elem;
	int			len;

	elem = malloc(sizeof(t_map_data));
	if (!elem)
		return (NULL);
	len = is_valid_line(line);
	if (len == 0)
		return (free(elem), NULL);
	elem->line = ft_strdup(line);
	if (!elem->line)
		return (free(elem), NULL);
	elem->length = len;
	elem->next = NULL;
	return (elem);
}

void	ft_map_add_back(t_map_data **lst, t_map_data *new)
{
	t_map_data	*actual;

	actual = *lst;
	if (!actual)
	{
		*lst = new;
		return ;
	}
	while (actual->next)
		actual = actual->next;
	actual->next = new;
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && 
			line[i] != '\n' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

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

void	free_map_data_list(t_map_data *data)
{
	t_map_data	*temp;

	while (data)
	{
		temp = data;
		data = data->next;
		free(temp->line);
		free(temp);
	}
}

void	reset_statics(int *player_count, int *map_started)
{
	*player_count = 0;
	*map_started = 0;
}

int	parse_map_line(char *line, t_map_data **data)
{
	t_map_data		*elem;
	static int		player_count = 0;
	static int		map_started = 0;

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

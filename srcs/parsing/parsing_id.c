/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:30:16 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:30:17 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	only_spaces(char *line)
{
	while (*line && is_space(*line))
		line++;
	return (*line == 0 || *line == '\n');
}

int	is_forbidden_next(char letter, char next_char)
{
	if (letter == 'N' && next_char == 'O')
		return (1);
	if (letter == 'S' && next_char == 'O')
		return (1);
	if (letter == 'W' && next_char == 'E')
		return (1);
	if (letter == 'E' && next_char == 'A')
		return (1);
	if ((letter == 'N' && (next_char == 'S' || next_char == 'W'
				|| next_char == 'E' || next_char == 'A')) || (letter == 'S'
			&& (next_char == 'N' || next_char == 'W' || next_char == 'E'
				|| next_char == 'A')) || (letter == 'W' && (next_char == 'N'
				|| next_char == 'S' || next_char == 'E' || next_char == 'A'))
		|| (letter == 'E' && (next_char == 'N' || next_char == 'S'
				|| next_char == 'W' || next_char == 'A')))
		return (1);
	return (0);
}

int	check_single_id(char *line, int i, char letter)
{
	int	j;

	if (line[i] != letter || !is_space(line[i + 1]))
		return (0);
	j = i + 1;
	while (is_space(line[j]))
		j++;
	if (line[j] == '\0' || line[j] == '\n')
		return (0);
	if (is_forbidden_next(letter, line[j]))
		return (0);
	return (1);
}

int	check_double_id(char *line, int i, char *id_str)
{
	if (ft_strncmp(&line[i], id_str, 2) != 0)
		return (0);
	return (is_space(line[i + 2]));
}

int	get_texture_id(char *line, int i)
{
	while (is_space(line[i]))
		i++;
	if (check_double_id(line, i, "NO"))
		return (0);
	if (check_double_id(line, i, "SO"))
		return (1);
	if (check_double_id(line, i, "WE"))
		return (2);
	if (check_double_id(line, i, "EA"))
		return (3);
	if (check_single_id(line, i, 'N'))
		return (0);
	if (check_single_id(line, i, 'S'))
		return (1);
	if (check_single_id(line, i, 'W'))
		return (2);
	if (check_single_id(line, i, 'E'))
		return (3);
	if (line[i] == 'F' && is_space(line[i + 1]))
		return (4);
	if (line[i] == 'C' && is_space(line[i + 1]))
		return (5);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:08:21 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:36:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == '\t' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
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
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			count++;
		i++;
	}
	return (count);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:09:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 10:09:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

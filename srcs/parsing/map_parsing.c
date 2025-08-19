/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 12:47:03 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-10 12:47:03 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == '\t' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W');
}

int is_valid_line(char *line)
{
	char *ptr;

	ptr = line;
	while(*ptr != '\n' && *ptr)
	{
		if(!is_valid_char(*ptr))
			return 0;
		ptr++;
	}
	return ptr - line;
}

t_map_data *new_elem(char *line)
{
	t_map_data *elem;

	elem = malloc(sizeof(t_map_data));
	if(!elem)
		return NULL;
	elem->line = ft_strdup(line);
	elem->length = is_valid_line(line);
	elem->next = NULL;
	return elem;
}

void ft_map_add_back(t_map_data **lst, t_map_data *new)
{
	t_map_data *actual;
	
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
int is_empty_line(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(is_space(line[i]))
			i++;
		else
			break ;
	}
	if(line[i] == '\n' || !line[i])
		return 1;
	return 0;
}

int parse_map_line(char *line, t_map_data **data)
{
	t_map_data *elem;
	elem = NULL;

	if(!is_empty_line(line) && is_valid_line(line))
	{
		elem = new_elem(line);
		if(!elem)
		{
			// TODO: free prev
			return 0;
		}
		ft_map_add_back(data, elem);
	}
	// t_map_data *temp = data;
	// static int test = 0;
	// while (temp)
	// {

	// 	printf("[%d] [line] %s\n[len] %d\n",test++, temp->line, temp->length);
	// 	temp = temp->next;
	// }
	return 1;
}

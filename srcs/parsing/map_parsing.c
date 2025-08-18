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
	elem->line = line;
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

t_map_data *parse_map_line(char *line)
{
	t_map_data *data;
	t_map_data *elem;

	data = NULL;
	if(!is_empty_line(line) && is_valid_line(line))
	{
		elem = new_elem(line);
		if(!elem)
		{
			// free prev
			return NULL;
		}
		ft_map_add_back(&data, elem);
	}
	else
	{
		// free prev
		return NULL;
	}
	// t_map_data *temp = data;
	// while (temp)
	// {
	// 	printf("[line] %s\n[len] %d\n", temp->line, temp->length);
	// 	temp = temp->next;
	// }
	char **test = get_map(data, NULL);
	for(int i = 0; test[i]; i++)
	{
		printf("%s", test[i]);
	}
	return data;
}

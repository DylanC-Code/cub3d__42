/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:02:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/01 12:55:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "get_next_line.h"

/* =============== Declaration =============== */

char				*get_next_line(int fd);
t_fd_node			*get_fd_node(t_fd_node **head, int fd);
int					read_and_save(t_fd_node *node);
char				*extract_line(t_fd_node *node);
void				cleanup_fd_node(int fd);

/* =============== Definition =============== */

static t_fd_node	*g_fd_list = NULL;

char	*get_next_line(int fd)
{
	t_fd_node	*node;
	char		*line;

	line = NULL;
	node = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, line, 0) < 0)
		return (cleanup_fd_node(fd), NULL);
	node = get_fd_node(&g_fd_list, fd);
	if (!node)
		return (NULL);
	if (read_and_save(node) == ERROR)
		return (cleanup_fd_node(fd), NULL);
	line = extract_line(node);
	if (!line)
		return (cleanup_fd_node(fd), NULL);
	if (!node->buffer || !(*node->buffer))
		cleanup_fd_node(fd);
	return (line);
}

void	cleanup_fd_node(int fd)
{
	t_fd_node	*prev;
	t_fd_node	*curr;

	prev = NULL;
	curr = g_fd_list;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				g_fd_list = curr->next;
			free(curr->buffer);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

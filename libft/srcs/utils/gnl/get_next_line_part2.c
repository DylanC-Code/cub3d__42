/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:02:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/01 12:58:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "get_next_line.h"

/* =============== Declaration =============== */

t_fd_node	*get_fd_node(t_fd_node **head, int fd);
int			read_and_save(t_fd_node *node);
char		*extract_line(t_fd_node *node);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, size_t start, size_t len);

/* =============== Definition =============== */

t_fd_node	*get_fd_node(t_fd_node **head, int fd)
{
	t_fd_node	*next;
	t_fd_node	*new_node;

	next = *head;
	while (next)
	{
		if (next->fd == fd)
			return (next);
		if (!next->next)
			break ;
		next = next->next;
	}
	new_node = malloc(sizeof(t_fd_node));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->next = NULL;
	if (!next)
		*head = new_node;
	else
		next->next = new_node;
	return (new_node);
}

int	read_and_save(t_fd_node *node)
{
	char	*buff;
	ssize_t	bytes_read;
	char	*tmp;

	if (!node)
		return (ERROR);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ERROR);
	bytes_read = 1;
	while (!ft_strchr(node->buffer, NEW_LINE) && bytes_read > 0)
	{
		bytes_read = read(node->fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(buff), SUCCESS);
		if (bytes_read < 0)
			return (free(buff), ERROR);
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(node->buffer, buff);
		if (!tmp)
			return (free(buff), ERROR);
		free(node->buffer);
		node->buffer = tmp;
	}
	return (free(buff), SUCCESS);
}

char	*extract_line(t_fd_node *node)
{
	const char	*p_new_line = ft_strchr(node->buffer, NEW_LINE);
	char		*new_buffer;
	char		*line;

	if (!node || !node->buffer || !*node->buffer)
		return (NULL);
	if (!p_new_line)
	{
		line = ft_strdup(node->buffer);
		free(node->buffer);
		node->buffer = NULL;
		return (line);
	}
	line = ft_substr(node->buffer, 0, p_new_line - node->buffer + 1);
	new_buffer = ft_strdup((char *)p_new_line + 1);
	free(node->buffer);
	node->buffer = new_buffer;
	return (line);
}

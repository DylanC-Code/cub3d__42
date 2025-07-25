/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:01:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 18:30:36 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define NEW_LINE '\n'

typedef struct s_fd_node
{
	int					fd;
	char				*buffer;
	struct s_fd_node	*next;
}						t_fd_node;

char					*get_next_line(int fd);

# define ERROR -1
# define SUCCESS 1

#endif

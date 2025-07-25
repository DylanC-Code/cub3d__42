/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:01:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/01 20:47:25 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define NEW_LINE '\n'
# define ERROR 0
# define SUCCESS 1

typedef struct s_fd_node
{
	int					fd;
	char				*buffer;
	struct s_fd_node	*next;
}						t_fd_node;

char					*get_next_line(int fd);

char					*ft_strjoin(char *s1, char *s2);
char					*ft_strchr(char *str, char c);
size_t					ft_strlen(char *str);
char					*ft_strdup(char *s);
char					*ft_substr(char *s, unsigned int start, size_t len);

#endif

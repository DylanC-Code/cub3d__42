/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:17:34 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/28 12:44:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <stdlib.h>

# define NEW_LINE '\n'

typedef struct s_fd_node
{
	int					fd;
	char				*buffer;
	struct s_fd_node	*next;
}						t_fd_node;

int						ft_atoi(const char *nptr);
long					ft_atol(char *nptr);
char					*ft_uitoa(unsigned int n);
char					*ft_uitoa_base(unsigned int nbr, char *base);
size_t					ft_strset(char *str, char c, size_t n);
char					*ft_itoa(int n);
char					*ft_itoa_base(long nbr, char *base);
char					**ft_split(char const *s, char c);
void					quick_sort(int *tab, size_t size);
size_t					ft_lower_bound(int arr[], size_t size, int target);
size_t					ft_lis_len(int arr[], size_t size);
char					*get_next_line(int fd);
void					cleanup_fd_node(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:05:53 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/24 09:28:32 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRS_H
# define STRS_H

# include "libft.h"

char	*ft_contains_substr(char *str, char *substr);
size_t	ft_count_occ(char *str, char c);
int		ft_ends_with(char *str, char *pattern);
void	ft_free_strs(char **strs);
int		ft_starts_with(char *str, char *pattern);
char	*ft_str_contains_any(char *str, char *set);
int		ft_ischarset(char c, const char *set);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s, t_garbage **gc);
char	*ft_strndup(const char *s, size_t n, t_garbage **gc);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2, t_garbage **gc);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));
void	ft_striteri(char *s, void (*f)(size_t, char *));

#endif

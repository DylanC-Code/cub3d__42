/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:02:27 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/28 12:43:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "get_next_line.h"

/* =============== Declaration =============== */

/* Basic */
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

/* =============== Definition =============== */

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] == c)
			return (str + i);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	const size_t	len = ft_strlen(s);
	char			*new;
	size_t			i;

	if (!s)
		return (NULL);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	char			*joined;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	str = NULL;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	str = malloc(len + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

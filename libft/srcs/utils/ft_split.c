/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:09:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/23 21:47:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(const char *str, char delimiter)
{
	int				in_word;
	unsigned int	count;
	size_t			i;

	in_word = FALSE;
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == delimiter)
			in_word = FALSE;
		else if (in_word == FALSE)
		{
			in_word = TRUE;
			count++;
		}
	}
	return (count);
}

static size_t	word_len(char *str, char delimiter)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == delimiter)
			return (i);
	return (i);
}

char	**ft_split(char const *s, char c, t_garbage **gc)
{
	const unsigned int	words_nb = count_words(s, c);
	char				*src;
	char				**result;
	size_t				word_index;
	size_t				i;

	src = (char *)s;
	result = gc_malloc(sizeof(char *) * (words_nb + 1), gc);
	if (!result)
		return (NULL);
	word_index = 0;
	i = 0;
	while (src[i])
	{
		while (src[i] == c)
			i++;
		if (!src[i])
			break ;
		result[word_index] = ft_strndup(src + i, word_len(src + i, c), gc);
		if (result[word_index++] == NULL)
			return (NULL);
		i += word_len(src + i, c);
	}
	result[word_index] = NULL;
	return (result);
}

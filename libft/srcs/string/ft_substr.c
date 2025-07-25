/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:29:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:14:29 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*str;
	size_t			i;

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

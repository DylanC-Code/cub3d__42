/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:01:19 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:14:41 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	const size_t	total_len = s1_len + s2_len;
	char			*str;
	size_t			i;

	str = malloc(total_len + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < total_len)
	{
		if (i < s1_len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1_len];
	}
	str[total_len] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:54:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 18:57:31 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	size_t	i;

	if (!s)
		return (NULL);
	src = (char *)s;
	i = -1;
	while (src[++i])
		if (src[i] == (char)c)
			return (src + i);
	if ((char)c == 0)
		return (src + i);
	return (NULL);
}

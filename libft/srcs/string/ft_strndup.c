/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/29 10:53:53 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

char	*ft_strndup(const char *s, size_t n, t_garbage **gc)
{
	const size_t	len = ft_strlen(s);
	char			*res;
	size_t			i;

	if (len < n)
		res = gc_malloc(len + 1, gc);
	else
		res = gc_malloc(n + 1, gc);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < n)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

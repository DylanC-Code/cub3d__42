/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:13:23 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:13:43 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	const size_t	len_src = ft_strlen(src);
	size_t			i;

	i = 0;
	if (siz < 1)
		return (len_src);
	while (i < siz - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

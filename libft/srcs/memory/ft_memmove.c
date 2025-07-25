/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:45:53 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:26:59 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s = src;
	unsigned char		*d;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = dest;
	i = -1;
	if (s < d)
		while (++i < n)
			d[n - 1 - i] = s[n - 1 - i];
	else
		while (++i < n)
			d[i] = s[i];
	return (dest);
}

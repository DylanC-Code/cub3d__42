/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:23:37 by dcastor           #+#    #+#             */
/*   Updated: 2025/04/28 16:11:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mptr;
	size_t			i;

	if (nmemb * size > INT_MAX)
		return (0);
	if (!nmemb || !size)
	{
		mptr = malloc(0);
		if (!mptr)
			return (NULL);
		return (mptr);
	}
	i = 0;
	mptr = malloc(size * nmemb);
	if (!mptr)
		return (NULL);
	while (i < size * nmemb)
	{
		mptr[i] = '\0';
		i++;
	}
	return (mptr);
}

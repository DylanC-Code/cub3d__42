/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:14:02 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:16:01 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_uintlen(unsigned int nbr)
{
	unsigned int	len;
	long			l_nbr;

	len = 0;
	l_nbr = nbr;
	if (l_nbr == 0)
		return (1);
	while (l_nbr)
	{
		l_nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	const unsigned int	len = ft_uintlen(n);
	char				*result;
	long				l_nbr;
	unsigned int		i;

	l_nbr = n;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = len - 1;
	if (!l_nbr)
		result[0] = '0';
	while (l_nbr)
	{
		result[i--] = l_nbr % 10 + '0';
		l_nbr /= 10;
	}
	result[len] = '\0';
	return (result);
}

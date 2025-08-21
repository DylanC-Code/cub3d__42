/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:49:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:36:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_intlen(int nbr)
{
	unsigned int	len;
	long			l_nbr;

	len = 0;
	l_nbr = nbr;
	if (l_nbr == 0)
		return (1);
	if (l_nbr < 0)
	{
		len++;
		l_nbr = -l_nbr;
	}
	while (l_nbr)
	{
		l_nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	const unsigned int	len = ft_intlen(n);
	const int			positive = n >= 0;
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
	if (!positive)
	{
		result[0] = '-';
		l_nbr = -l_nbr;
	}
	while (l_nbr)
	{
		result[i--] = l_nbr % 10 + '0';
		l_nbr /= 10;
	}
	result[len] = '\0';
	return (result);
}

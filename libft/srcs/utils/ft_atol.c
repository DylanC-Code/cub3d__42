/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:15:33 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:36:47 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "validate.h"

static int	is_space(int c)
{
	const char	*white_spaces = " \f\n\r\t\v";
	size_t		i;

	i = -1;
	while (white_spaces[++i])
		if (c == white_spaces[i])
			return (TRUE);
	return (FALSE);
}

static void	*jump_whitespaces(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (!is_space(s[i]))
			return (s + i);
	return (s + i);
}

long	ft_atol(char *nptr)
{
	long	nbr;
	int		sign;

	nptr = jump_whitespaces((char *)nptr);
	nbr = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr++ - '0');
	return (nbr * sign);
}

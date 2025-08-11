/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:49:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:36:32 by dcastor          ###   ########.fr       */
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

int	ft_atoi(const char *nptr)
{
	int		sign;
	char	*ptr;
	int		res;

	ptr = jump_whitespaces((char *)nptr);
	sign = 1;
	res = 0;
	if (*ptr == '-' || *ptr == '+')
		if (*ptr++ == '-')
			sign = -1;
	while (*ptr && ft_isdigit(*ptr))
		res = res * 10 + (*ptr++ - '0');
	return (res * sign);
}

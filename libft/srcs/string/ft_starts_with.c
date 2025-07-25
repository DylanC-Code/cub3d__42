/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:13:14 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/28 12:18:21 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

int	ft_starts_with(char *str, char *pattern)
{
	const size_t	s_len = ft_strlen(str);
	const size_t	p_len = ft_strlen(pattern);

	if (p_len > s_len)
		return (FALSE);
	while (str && pattern)
	{
		if (!*pattern)
			break ;
		if (*str != *pattern)
			return (FALSE);
		str++;
		pattern++;
	}
	return (TRUE);
}

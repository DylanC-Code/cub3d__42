/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:46:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:34:58 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

int	ft_ends_with(char *str, char *pattern)
{
	const size_t	pattern_len = ft_strlen(pattern);
	const size_t	str_len = ft_strlen(str);

	if (pattern_len > str_len)
		return (FALSE);
	return (ft_strncmp(str + str_len - pattern_len, pattern, pattern_len) == 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:11:33 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/01 11:15:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_contains_substr(char *str, char *substr)
{
	const size_t	str_len = ft_strlen(str);
	const size_t	substr_len = ft_strlen(substr);
	size_t			i;

	if (str_len < substr_len)
		return (NULL);
	i = -1;
	while (++i < str_len)
		if (!ft_strncmp(str + i, substr, substr_len))
			return (str + i);
	return (NULL);
}

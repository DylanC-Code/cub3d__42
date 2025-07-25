/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:49:57 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:15:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

char	*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	const size_t	len = ft_strlen(s);
	size_t			i;
	char			*result;

	i = -1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (++i < len)
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}

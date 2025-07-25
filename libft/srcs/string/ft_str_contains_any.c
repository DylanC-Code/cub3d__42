/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_contains_any.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:52:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/23 18:17:59 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_contains_any(char *str, char *set)
{
	char	*addr;

	addr = NULL;
	while (str && *str)
	{
		addr = ft_strchr(set, *str);
		if (addr)
			return (str);
		str++;
	}
	return (NULL);
}

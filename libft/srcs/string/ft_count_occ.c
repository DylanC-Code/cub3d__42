/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 14:48:42 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_occ(char *str, char c)
{
	size_t	count;

	count = 0;
	while (str && *str)
		if (*str++ == c)
			count++;
	return (count);
}

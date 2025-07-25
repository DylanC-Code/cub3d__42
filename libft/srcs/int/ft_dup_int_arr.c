/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:08:41 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 14:38:05 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*ft_dup_int_arr(int arr[], size_t size)
{
	int		*new_arr;
	size_t	i;

	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return (NULL);
	i = -1;
	while (++i < size)
		new_arr[i] = arr[i];
	return (new_arr);
}

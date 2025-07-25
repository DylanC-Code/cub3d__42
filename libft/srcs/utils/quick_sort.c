/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:16:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 15:51:47 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_int(int *n1, int *n2)
{
	const int	tmp = *n1;

	*n1 = *n2;
	*n2 = tmp;
}

void	quick_sort(int *tab, size_t size)
{
	const int	pivot = tab[size - 1];
	size_t		last_smaller;
	size_t		i;

	if (size <= 1)
		return ;
	i = -1;
	last_smaller = -1;
	while (++i < size - 1)
		if (tab[i] <= pivot)
			swap_int(&tab[++last_smaller], tab + i);
	swap_int(&tab[size - 1], &tab[last_smaller + 1]);
	quick_sort(tab, last_smaller + 1);
	quick_sort(&tab[last_smaller + 2], size - (last_smaller + 2));
}

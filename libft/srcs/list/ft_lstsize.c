/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:38:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:21:46 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*actual;

	count = 0;
	actual = lst;
	while (actual)
	{
		count++;
		actual = actual->next;
	}
	return (count);
}

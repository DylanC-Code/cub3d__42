/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:41:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:37:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsome(t_list *head, int (*f)(t_list *))
{
	while (head)
	{
		if (f(head))
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

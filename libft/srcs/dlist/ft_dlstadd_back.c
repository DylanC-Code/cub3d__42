/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:18:52 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/20 09:46:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **p_head, t_dlist *new)
{
	if (!*p_head)
	{
		*p_head = new;
		return ;
	}
	while (*p_head && (*p_head)->next)
		*p_head = (*p_head)->next;
	(*p_head)->next = new;
	new->prev = *p_head;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-11 13:46:07 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-11 13:46:07 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	add_gb_to_back(t_garbage **garbage_list, t_garbage *new_gb);

void	*gc_malloc(size_t size, t_garbage **garbage_list)
{
	t_garbage	*new_gb;
	void		*alloc;

	new_gb = ft_calloc(1, sizeof(t_garbage));
	alloc = malloc(size);
	if (!alloc || !new_gb)
	{
		free(alloc);
		free(new_gb);
		perror("gc_malloc");
		return (NULL);
	}
	ft_bzero(new_gb, sizeof(t_garbage));
	ft_bzero(alloc, size);
	new_gb->alloc = alloc;
	add_gb_to_back(garbage_list, new_gb);
	return (alloc);
}

void	gc_cleanup(t_garbage **garbage_list)
{
	t_garbage	*next;
	t_garbage	*curr;

	if (!garbage_list)
		return ;
	curr = *garbage_list;
	while (curr)
	{
		next = curr->next;
		free(curr->alloc);
		free(curr);
		curr = next;
	}
	*garbage_list = NULL;
}

void	add_to_gc(t_garbage **gc, void *alloc)
{
	t_garbage	*new_gb;

	if (!alloc)
		return ;
	new_gb = ft_calloc(1, sizeof(t_garbage));
	if (!new_gb)
	{
		perror("gc_malloc");
		free(alloc);
		return ;
	}
	new_gb->alloc = alloc;
	add_gb_to_back(gc, new_gb);
}

static void	add_gb_to_back(t_garbage **garbage_list, t_garbage *new_gb)
{
	t_garbage	*next;

	if (!garbage_list)
		return ;
	next = *garbage_list;
	if (!next)
	{
		*garbage_list = new_gb;
		return ;
	}
	while (next->next)
		next = next->next;
	next->next = new_gb;
}

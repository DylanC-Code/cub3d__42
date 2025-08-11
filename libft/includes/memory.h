/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:39:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/26 16:21:15 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <sys/types.h>
# include <stdio.h>

typedef struct s_garbage
{
	void				*alloc;
	struct s_garbage	*next;
}						t_garbage;

void					*gc_malloc(size_t size, t_garbage **garbage_list);
void					add_to_gc(t_garbage **garbage_list, void *alloc);
void					gc_cleanup(t_garbage **garbage_list);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:30 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/27 16:58:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "bit.h"
# include "char.h"
# include "dlist.h"
# include "int.h"
# include "list.h"
# include "mem.h"
# include "number.h"
# include "output.h"
# include "strs.h"
# include "utils.h"
# include "validate.h"
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* Range */
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/* Status */
typedef int	t_status;

# define ERROR 0
# define NOOP -1
# define SUCCESS 1

/* Bool */
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

#endif

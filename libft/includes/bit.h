/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:20:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:31:31 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_H
# define BIT_H

# include "libft.h"

int				bit_is_set(unsigned int value, unsigned char bit_index);
unsigned int	set_bit(unsigned int value, unsigned char bit_index);

#endif

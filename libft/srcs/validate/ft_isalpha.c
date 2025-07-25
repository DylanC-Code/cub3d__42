/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:26:23 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 10:37:26 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	const int	is_upper = (c >= 'a' && c <= 'z');
	const int	is_lower = (c >= 'A' && c <= 'Z');

	return (is_upper || is_lower);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:18:32 by dcastor           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strs.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const size_t	s1_len = ft_strlen(s1);
	size_t			i_start;
	size_t			i_end;
	char			*str;
	size_t			i;

	i_start = -1;
	i_end = s1_len;
	while (++i_start < s1_len)
		if (!ft_ischarset(s1[i_start], set))
			break ;
	while (--i_end > i_start)
		if (!ft_ischarset(s1[i_end], set))
			break ;
	str = malloc(s1_len - i_start - (s1_len - i_end) + 2);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < (i_end - i_start + 1))
		str[i] = s1[i_start + i];
	str[i] = '\0';
	return (str);
}

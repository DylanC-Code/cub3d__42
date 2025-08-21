/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-21 03:10:55 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-21 03:10:55 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*map_to_string(char **map)
{
	char	*result;
	int		i;

	if (!map || !map[0])
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (map[i])
	{
		result = join_and_free(result, map[i]);
		if (!result)
			return (NULL);
		if (map[i + 1])
		{
			result = join_and_free(result, "");
			if (!result)
				return (NULL);
		}
		i++;
	}
	return (result);
}

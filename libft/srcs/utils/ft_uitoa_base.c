/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:14:11 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/07 22:34:51 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static unsigned int	get_len(ssize_t nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

static void	fill_str(char *res, long nbr, char *base, int len)
{
	int	base_len;

	base_len = check_base(base);
	while (nbr)
	{
		res[len--] = base[nbr % base_len];
		nbr /= base_len;
	}
}

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	const unsigned int	base_len = check_base(base);
	unsigned int		len;
	char				*res;

	len = get_len(nbr, base_len);
	if (base_len < 2)
		return (NULL);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nbr == 0)
		res[0] = base[0];
	else
		fill_str(res, nbr, base, len);
	return (res);
}

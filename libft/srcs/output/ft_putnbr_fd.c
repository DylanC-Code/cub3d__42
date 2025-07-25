/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:40:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/22 12:20:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned char	ft_intlen(int nbr)
{
	unsigned int	len;
	long			l_nbr;

	len = 0;
	l_nbr = nbr;
	if (l_nbr == 0)
		return (1);
	if (l_nbr < 0)
	{
		len++;
		l_nbr = -l_nbr;
	}
	while (l_nbr)
	{
		l_nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	const unsigned char	n_len = ft_intlen(n);
	char				buffer[14];
	long				nbr;
	unsigned char		i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr = -nbr;
	}
	if (!nbr)
		buffer[0] = '0';
	while (nbr)
	{
		buffer[n_len - i - 1] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	write(fd, buffer, n_len);
}

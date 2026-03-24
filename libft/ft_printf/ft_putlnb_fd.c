/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnb_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:30:54 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:28:00 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_abs(long long lnb)
{
	if (lnb >= 0)
		return (lnb);
	return (-lnb);
}

int	ft_putlnb_rec(long lnb, int fd)
{
	int	count;

	count = 1;
	if (lnb >= 10)
		count += ft_putlnb_rec(lnb / 10, fd);
	ft_putchar_fd((lnb % 10) + '0', fd);
	return (count);
}

int	ft_putlnb_fd(long nb, int fd)
{
	long long	lnb;
	int			count;

	count = 0;
	lnb = ft_abs(nb);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		count++;
	}
	return (count + ft_putlnb_rec(lnb, fd));
}

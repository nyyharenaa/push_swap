/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:41:57 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/19 09:32:24 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_negative(long int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static unsigned int	count_len_nb(long int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	fill_tab(char *tab, long int n, int len_nb)
{
	tab[--len_nb] = '\0';
	if (n == 0)
		tab[--len_nb] = '0';
	while (n != 0)
	{
		tab[--len_nb] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len_nb;
	long int	nb;

	len_nb = 0;
	nb = (long int)n;
	if (is_negative(n))
	{
		nb = nb * (-1);
		len_nb = 1;
	}
	len_nb += count_len_nb(nb);
	str = (char *)malloc(sizeof(char) * (len_nb + 1));
	if (!str)
		return (NULL);
	else
		fill_tab(str, nb, (len_nb + 1));
	if (is_negative(n))
		*str = '-';
	return (str);
}

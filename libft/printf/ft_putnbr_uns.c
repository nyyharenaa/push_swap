/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:21:15 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/28 12:25:13 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int n)
{
	ssize_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_uns(n / 10);
	count += ft_putchar(n % 10 + '0');
	return ((int)count);
}

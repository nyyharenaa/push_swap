/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:21:41 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/28 12:47:58 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long n, int is_uppercase)
{
	ssize_t	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, is_uppercase);
	if (is_uppercase)
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		count += ft_putchar("0123456789abcdef"[n % 16]);
	return ((int)count);
}

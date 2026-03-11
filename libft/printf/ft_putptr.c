/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:23:56 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/28 12:42:54 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	ssize_t	count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr("(nil)");
		return ((int)count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_hex((unsigned long long)ptr, 0);
	return ((int)count);
}

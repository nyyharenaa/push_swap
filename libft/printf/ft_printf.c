/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:44:11 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/01 12:22:51 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(va_list arg, const char *format, int *count)
{
	if (*format == 'c')
		*count += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		*count += ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		*count += ft_putptr(va_arg(arg, void *));
	else if (*format == 'd' || *format == 'i')
		*count += ft_putnbr(va_arg(arg, int));
	else if (*format == 'u')
		*count += ft_putnbr_uns(va_arg(arg, unsigned int));
	else if (*format == 'x')
		*count += ft_putnbr_hex(va_arg(arg, unsigned int), 0);
	else if (*format == 'X')
		*count += ft_putnbr_hex(va_arg(arg, unsigned int), 1);
	else if (*format == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check(arg, format, &count);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:08:57 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:40:29 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_conv(int fd, char c, va_list list);

int	ft_dprintf(int fd, const char *f, ...)
{
	int			index;
	va_list		list;
	int			count;
	int			t_count;

	index = 0;
	count = 0;
	if (!f || fd < 0)
		return (-1);
	va_start(list, f);
	while (count != -1 && f[index])
	{
		t_count = 0;
		if (f[index] == '%')
			t_count = handle_conv(fd, f[++index], list);
		else
			t_count = ft_putchar_fd(f[index], fd);
		count += t_count;
		if (t_count == -1)
			count = -1;
		else
			index++;
	}
	va_end(list);
	return (count);
}

static int	handle_conv(int fd, char c, va_list list)
{
	if (c == 'c')
		return (ft_print_char_l(fd, list));
	else if (c == 's')
		return (ft_print_str_l(fd, list));
	else if (c == 'p')
		return (ft_print_ptr_l(fd, list));
	else if (c == 'd')
		return (ft_print_int_l(fd, list));
	else if (c == 'i')
		return (ft_print_int_l(fd, list));
	else if (c == 'u')
		return (ft_print_uint_l(fd, list));
	else if (c == 'x')
		return (ft_print_lhex_l(fd, list));
	else if (c == 'X')
		return (ft_print_uhex_l(fd, list));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (-1);
}

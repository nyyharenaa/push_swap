/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:30:16 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:22:11 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_lhex(int fd, uintptr_t nb)
{
	char	*base;

	base = "0123456789abcdef";
	return (ft_putunb_base_fd(nb, base, fd));
}

int	ft_print_ptr_l(int fd, va_list list)
{
	uintptr_t	u_ptr;
	int			count;

	count = 0;
	u_ptr = va_arg(list, uintptr_t);
	if (u_ptr)
	{
		count = ft_putstr_fd("0x", fd);
		count += ft_print_lhex(fd, u_ptr);
	}
	else
		count = ft_putstr_fd("(nil)", fd);
	return (count);
}

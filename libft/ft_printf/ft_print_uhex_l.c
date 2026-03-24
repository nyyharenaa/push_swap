/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:40:34 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:22:41 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uhex_l(int fd, va_list list)
{
	unsigned int	nb;
	char			*base;

	nb = va_arg(list, unsigned int);
	base = "0123456789ABCDEF";
	return (ft_putunb_base_fd(nb, base, fd));
}

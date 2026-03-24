/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:18:12 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:22:48 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uint_l(int fd, va_list list)
{
	unsigned int	unb;

	unb = va_arg(list, unsigned int);
	return (ft_putunb_fd(unb, fd));
}

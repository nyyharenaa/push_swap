/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:03:36 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:21:16 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int_l(int fd, va_list list)
{
	int	nb;

	nb = va_arg(list, int);
	return (ft_putlnb_fd(nb, fd));
}

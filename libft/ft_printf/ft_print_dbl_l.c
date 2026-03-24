/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dbl_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:20:22 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 09:31:58 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_dbl_l(int fd, va_list list)
{
	int		count;
	float	full;
	int		int_part;
	int		dec_part;

	count = 0;
	full = va_arg(list, double);
	int_part = (int)full;
	dec_part = (int)((full - int_part) * 100);
	count = ft_putlnb_fd(int_part, fd);
	count += ft_putchar_fd('.', fd);
	count += ft_putlnb_fd(dec_part, fd);
	if (dec_part < 10)
		count += ft_putchar_fd('0', fd);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:19:35 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:23:30 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunb_fd(unsigned int nb, int fd)
{
	int	count;

	count = 1;
	if (nb >= 10)
		count += ft_putunb_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
	return (count);
}

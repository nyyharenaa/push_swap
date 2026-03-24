/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:01:45 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:27:52 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_basevalid(const char *b)
{
	int	index;
	int	valid;

	valid = 1;
	index = 0;
	while (valid && b[index])
	{
		valid = ft_strchr(b + index + 1, b[index]) == 0;
		index++;
	}
	return ((valid) * (index > 1) * index);
}

int	ft_putunb_base_fd_rec(uintptr_t nb, const char *b, int b_val, int fd)
{
	int	count;

	count = 1;
	if (nb >= (unsigned int)b_val)
		count += ft_putunb_base_fd_rec(nb / b_val, b, b_val, fd);
	ft_putchar_fd(b[nb % b_val], fd);
	return (count);
}

int	ft_putunb_base_fd(uintptr_t nb, const char *b, int fd)
{
	int			b_val;
	int			count;

	count = 0;
	b_val = ft_is_basevalid(b);
	if (b_val == 0)
		return (0);
	return (count + ft_putunb_base_fd_rec(nb, b, b_val, fd));
}

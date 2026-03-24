/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:01:50 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 08:22:33 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str_l(int fd, va_list list)
{
	char	*str;

	str = va_arg(list, char *);
	if (str == 0)
		str = "(null)";
	return (ft_putstr_fd(str, fd));
}

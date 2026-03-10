/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:40:22 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/22 12:06:24 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	v;

	v = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = v;
		i++;
	}
	return ((void *)str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:40:09 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/22 17:31:22 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	char	*str;

	chr = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	else
		return (NULL);
}

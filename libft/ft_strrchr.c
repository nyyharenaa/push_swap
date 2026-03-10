/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:39:01 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/18 12:38:58 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*ret;
	char	*str;

	str = (char *)s;
	chr = (char)c;
	ret = NULL;
	if (chr != '\0')
	{
		while (*str)
		{
			if (*str == chr)
				ret = str;
			str++;
		}
		return (ret);
	}
	else
	{
		while (*str)
			str++;
		ret = str;
		return (ret);
	}
}

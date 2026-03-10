/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:39:08 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/18 12:58:08 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_ptr;
	char	*little_ptr;
	size_t	i;

	i = 0;
	big_ptr = (char *)big;
	little_ptr = (char *)little;
	if (*little_ptr == '\0')
		return (big_ptr);
	while (*big_ptr && i < len)
	{
		if (len >= ft_strlen(little_ptr) + i)
		{
			if (ft_strncmp(big_ptr, little_ptr, ft_strlen(little_ptr)) == 0)
				return (big_ptr);
		}
		i++;
		big_ptr++;
	}
	return (NULL);
}

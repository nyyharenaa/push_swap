/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:39:55 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/11 11:39:22 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (!s1 && !s2)
		return (0);
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	res = malloc(sizeof(char) * (s2_len + s1_len + 1));
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, s2_len + s1_len + 1);
	if (s2)
		ft_strlcpy(res + s1_len, s2, s2_len + 1);
	res[s1_len + s2_len] = 0;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:16:56 by ny-handr          #+#    #+#             */
/*   Updated: 2026/02/19 09:45:58 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_word(char const *s, char c)
{
	unsigned int	nb;

	nb = 0;
	while (*s && *s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			nb++;
		s++;
	}
	return (nb + 1);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	if (!s)
		return (NULL);
	tab = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			tab[j++] = ft_substr(s, start, i - start);
	}
	tab[j] = NULL;
	return (tab);
}

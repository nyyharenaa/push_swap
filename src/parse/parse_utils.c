/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:05:03 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 12:23:20 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_lstchr(t_list *lst, void *content)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, content, ft_strlen(content) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_dup(t_list *av)
{
	t_list	*node;
	t_list	*temp;
	size_t	len;

	node = av;
	while (av)
	{
		temp = av->next;
		while (temp)
		{
			len = ft_strlen(av->content);
			if (!ft_strncmp(av->content, temp->content, len + 1))
			{
				ft_dprintf(2, "Error\n");
				ft_lstclear(&node, free);
				exit(1);
			}
			temp = temp->next;
		}
		av = av->next;
	}
}

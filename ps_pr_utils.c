/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:05:03 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 16:55:22 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parser.h"

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

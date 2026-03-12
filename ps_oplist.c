/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oplist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:40:35 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 09:52:29 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_oplist.h"

void	oplst_add(t_list **lst, char *op)
{
	ft_lstadd_back(lst, ft_lstnew(op));
}

void	oplst_clear(t_list **lst)
{
	ft_lstclear(lst, NULL);
}

int	oplst_print(t_list *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
		count++;
	}
	return (count);
}

int	oplst_count(t_list *lst, char *op)
{
	int		count;

	count = 0;
	while (lst)
	{
		if (lst->content && !ft_strncmp(lst->content, op, 3))
			count++;
		lst = lst->next;
	}
	return (count);
}


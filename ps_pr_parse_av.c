/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:48:55 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 10:51:02 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_int(t_stack *stack, t_list *lst)
{
	t_list		*temp;
	t_st_node	*node;
	char		*str;

	temp = lst;
	while (lst)
	{
		if (ft_isnumber((char *)lst->content))
		{
			str = ft_strdup((char *)lst->content);
			node = st_new(ft_atoi(str));
			st_add_back(stack, node);
			free(str);
		}
		lst = lst->next;
	}
}

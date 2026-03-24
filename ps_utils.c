/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:28:22 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 16:56:22 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stack	create_stack()
{
	t_stack	st;

	st.first = NULL;
	st.last = NULL;
	st.size = 0;
	return (st);
}

int	isnumber(const char *str)
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

void	fill_stack(t_stack *stack, t_list *lst)
{
	t_list		*temp;
	t_st_node	*node;

	temp = lst;
	while (lst)
	{
		if (isnumber((char *)lst->content))
		{
			node = st_new(ft_atoi((char *)lst->content));
			st_add_back(stack, node);
		}
		lst = lst->next;
	}
}
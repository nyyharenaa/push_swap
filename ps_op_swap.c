/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:44:23 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/10 14:08:29 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	sa(t_stack *a, t_stack *b)
{
	t_st_node	*node;

	if (a->size < 2)
		return ;
	node = a->first->next;
	a->first->next = node->next;
	node->next = a->first;
	a->first = node;
	(void)b;
}

void	sb(t_stack *a, t_stack *b)
{
	sa(b, a);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
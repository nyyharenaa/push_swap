/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:45:03 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/10 14:36:58 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	ra(s_stack *a, s_stack *b)
{
	t_st_node	*node;

	if (a->size < 2)
		return ;
	node = a->first;
	a->first = node->next;
	a->last->next = node;
	node->next = NULL;
	a->last = node;
	(void)b;
}

void	rb(s_stack *a, s_stack *b)
{
	ra(b, a);
}

void	rr(s_stack *a, s_stack *b)
{
	ra(a, b);
	rb(a, b);
}
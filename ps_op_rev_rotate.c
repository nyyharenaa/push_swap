/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:45:15 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/10 14:44:12 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	rra(t_stack *a, t_stack *b)
{
	t_st_node	*second_last;
	t_st_node	*last;

	if (a->size < 2)
		return ;
	second_last = st_second_last(*a);
	last = a->last;
	a->last->next = a->first;
	a->first = last;
	second_last->next = NULL;
	a->last = second_last;
	(void)b;
}

void	rrb(t_stack *a, t_stack *b)
{
	rra(b, a);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
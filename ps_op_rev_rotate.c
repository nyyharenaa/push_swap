/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:45:15 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 21:42:44 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

static void	_rev_rorate(t_stack *a, t_stack *b)
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

void	rra(t_stack *a, t_stack *b, t_list **oplst)
{
	_rev_rorate(a, b);
	oplst_add(oplst, "rra");
}

void	rrb(t_stack *a, t_stack *b, t_list **oplst)
{
	_rev_rorate(b, a);
	oplst_add(oplst, "rrb");
}

void	rrr(t_stack *a, t_stack *b, t_list **oplst)
{
	_rev_rorate(a, b);
	_rev_rorate(b, a);
	oplst_add(oplst, "rrr");
}

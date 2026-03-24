/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:45:03 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:30:51 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	_rotate(t_stack *a, t_stack *b)
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

void	ra(t_stack *a, t_stack *b, t_list **oplst)
{
	_rotate(a, b);
	if (oplst)
		oplst_add(oplst, "ra");
}

void	rb(t_stack *a, t_stack *b, t_list **oplst)
{
	_rotate(b, a);
	if (oplst)
		oplst_add(oplst, "rb");
}

void	rr(t_stack *a, t_stack *b, t_list **oplst)
{
	_rotate(a, b);
	_rotate(b, a);
	if (oplst)
		oplst_add(oplst, "rr");
}

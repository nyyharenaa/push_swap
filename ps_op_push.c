/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:44:59 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 21:55:52 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

static void	_push(t_stack *a, t_stack *b)
{
	t_st_node	*node;

	if (b->size == 0)
		return ;
	node = b->first->next;
	b->first->next = a->first;
	a->first = b->first;
	if (a->last == NULL)
		a->last = a->first;
	b->first = node;
	if (node == NULL)
		b->last = NULL;
	a->size++;
	b->size--;
}

void	pa(t_stack *a, t_stack *b, t_list **oplst)
{
	_push(a, b);
	oplst_add(oplst, "pa");
}

void	pb(t_stack *a, t_stack *b, t_list **oplst)
{
	_push(b, a);
	oplst_add(oplst, "pb");
}

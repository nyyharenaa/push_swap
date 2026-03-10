/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:44:59 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/10 14:41:58 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	pa(t_stack *a, t_stack *b)
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
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	pa(b, a);
}
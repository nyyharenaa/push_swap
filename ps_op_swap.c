/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:44:23 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:31:23 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_operation.h"

void	_swap(t_stack *a, t_stack *b)
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

void	sa(t_stack *a, t_stack *b, t_list **oplst)
{
	_swap(a, b);
	if (oplst)
		oplst_add(oplst, "sa");
}

void	sb(t_stack *a, t_stack *b, t_list **oplst)
{
	_swap(b, a);
	if (oplst)
		oplst_add(oplst, "sb");
}

void	ss(t_stack *a, t_stack *b, t_list **oplst)
{
	_swap(a, b);
	_swap(b, a);
	if (oplst)
		oplst_add(oplst, "ss");
}

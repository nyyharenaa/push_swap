/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:54:33 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 21:41:30 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static int	find_min(t_stack *st);

t_list	*al_simple(t_stack *st_a, t_stack *st_b)
{
	t_list	*oplst;
	int		index;
	int		count;

	oplst = NULL;
	while (st_a && st_b && st_a->first)
	{
		count = find_min(st_a);
		index = 0;
		while (index < count)
		{
			ra(st_a, st_b, &oplst);
			index++;
		}
		pb(st_a, st_b, &oplst);
	}
	while (st_a && st_b && st_b->first)
		pa(st_a, st_b, &oplst);
	return (oplst);
}

static int	find_min(t_stack *st)
{
	int			min;
	int			index;
	int			res;
	t_st_node	*node;

	res = -1;
	index = 0;
	node = NULL;
	if (st)
		node = st->first;
	if (node)
		min = node->value;
	while (node)
	{
		if (min > node->value)
		{
			min = node->value;
			res = index;
		}
		node = node->next;
		index++;
	}
	return (res);
}

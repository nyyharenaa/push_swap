/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:16:31 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 20:29:45 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

int	get_bit_count(int n);
int	get_max_val(t_stack st_a);

t_list	*al_complex(t_stack *st_a, t_stack *st_b)
{
	t_list		*oplist;
	t_st_node	*node;
	int			b_count;

	oplist = NULL;
	b_count = get_bit_count(get_max_val(*st_a));
	while (--b_count)
	{
		node = st_a->first;
		while (node)
		{
			if ((node->value & (1 << b_count)) == 0)
			{
				oplst_add(&oplist, "pb");
				pb(st_a, st_b);
			}
			node = node->next;
			oplst_add(&oplist, "ra");
			ra(st_a, st_b);
		}
	}
	node = st_a->first;
	while (node)
	{
		pa(st_a, st_b);
		oplst_add(&oplist, "pa");
		node = node->next;
	}
	return (oplist);
}

int	get_max_val(t_stack st_a)
{
	t_st_node	*node;
	int			max;

	node = st_a.first;
	if (!node)
		return (INT_MIN);
	max = node->value;
	while (node)
	{
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	get_bit_count(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n >> 1;
		count++;
	}
	return (count);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_special_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:30:58 by todina-r          #+#    #+#             */
/*   Updated: 2026/04/08 08:09:50 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static void	three_elem(t_stack *st_a, t_stack *st_b, t_list **oplst);
static void	push_min(t_stack *st_a, t_stack *st_b, t_list **oplst);
static int	find_min_index(t_stack st);

t_list	*al_special_case(t_stack *st_a, t_stack *st_b)
{
	t_list	*oplst;

	oplst = NULL;
	if (st_a->size == 2)
		sa(st_a, st_b, &oplst);
	else
	{
		while (st_a->size > 3)
			push_min(st_a, st_b, &oplst);
		three_elem(st_a, st_b, &oplst);
		while (st_b->size > 0)
			pa(st_a, st_b, &oplst);
	}
	return (oplst);
}

static void	three_elem(t_stack *st_a, t_stack *st_b, t_list **oplst)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = st_a->first->value;
	v2 = st_a->first->next->value;
	v3 = st_a->last->value;
	if (is_sorted(*st_a))
		return ;
	if (v1 > v2 && v1 < v3)
		sa(st_a, st_b, oplst);
	else if (v1 > v2 && v1 > v3)
		ra(st_a, st_b, oplst);
	else
		sa(st_a, st_b, oplst);
	three_elem(st_a, st_b, oplst);
}

static void	push_min(t_stack *st_a, t_stack *st_b, t_list **oplst)
{
	int	min_index;

	min_index = find_min_index(*st_a);
	if (min_index < (int)(st_a->size / 2))
		while (min_index-- > 0)
			ra(st_a, st_b, oplst);
	else
		while (++min_index <= (int)(st_a->size))
			rra(st_a, st_b, oplst);
	pb(st_a, st_b, oplst);
}

static int	find_min_index(t_stack st)
{
	int			min;
	int			index;
	int			res;
	t_st_node	*node;

	res = -1;
	index = 0;
	node = NULL;
	node = st.first;
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

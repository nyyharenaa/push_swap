/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:16:31 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/16 14:46:00 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static int	ft_sqrt(int n);
static int	find_max(t_stack st);

t_list	*al_medium(t_stack *st_a, t_stack *st_b)
{
	t_list	*oplst;
	int		bucket_count;
	int		bucket_size;
	int		bucket_index;
	int		bucket_slot;
	int		max;
	int		node_index;

	oplst = NULL;
	bucket_count = ft_sqrt(st_a->size);
	bucket_size = st_a->size / bucket_count;
	bucket_slot = bucket_size;
	bucket_index = 0;
	while (st_a->first)
	{
		max = (bucket_index + 1) * bucket_size;
		if (st_a->first->value < max)
		{
			pb(st_a, st_b, &oplst);
			bucket_slot--;
		}
		else
			ra(st_a, st_b, &oplst);
		if (bucket_slot == 0)
		{
			bucket_slot = bucket_size;
			bucket_index++;
		}
	}
	while (st_b->first)
	{
		node_index = find_max(*st_b);
		if (node_index > 0 && node_index > ((int)st_b->size - node_index))
		{
			node_index = st_b->size - node_index;
			while (node_index-- > 0)
				rrb(st_a, st_b, &oplst);
		}
		else
			while (node_index-- > 0)
				rb(st_a, st_b, &oplst);
		pa(st_a, st_b, &oplst);
	}
	return (oplst);
}

static int	ft_sqrt(int n)
{
	int	res;

	res = 0;
	while (res < n)
	{
		res++;
		if (res * res > n)
			return (res - 1);
	}
	return (0);
}

static int	find_max(t_stack st)
{
	t_st_node	*node;
	int			index;
	int			res;
	int			max;

	res = 0;
	index = 0;
	node = st.first;
	if (node)
		max = node->value;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			res = index;
		}
		node = node->next;
		index++;
	}
	return (res);
}


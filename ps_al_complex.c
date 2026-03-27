/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:16:31 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/27 15:21:05 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static size_t	get_max_bits(t_stack *st);

t_list	*al_complex(t_stack *st_a, t_stack *st_b)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	max_bits;
	t_list	*oplst;

	i = 0;
	oplst = NULL;
	size = st_a->size;
	max_bits = get_max_bits(st_a);
	while (i++ < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (!((st_a->first->value >> (i - 1)) & 1))
				pb(st_a, st_b, &oplst);
			else
				ra(st_a, st_b, &oplst);
		}
		while (st_b->size > 0)
			pa(st_a, st_b, &oplst);
	}
	return (oplst);
}

static size_t	get_max_bits(t_stack *st)
{
	size_t	max_bits;
	size_t	size;

	size = st->size;
	max_bits = 0;
	while ((1 << max_bits) < size)
		max_bits++;
	return (max_bits);
}

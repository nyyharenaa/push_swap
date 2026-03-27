/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_special_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:30:58 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/27 09:13:44 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static void		three_elem(t_stack *st_a, t_stack *st_b, t_list **oplst);

t_list	*al_special_case(t_stack *st_a, t_stack *st_b)
{
	t_list	*oplst;

	oplst = NULL;
	if (st_a->size > 3)
		return (NULL);
	if (st_a->size == 2)
		sa(st_a, st_b, &oplst);
	else if (st_a->size == 3)
		three_elem(st_a, st_b, &oplst);
	return (oplst);
}

static void	three_elem(t_stack *st_a, t_stack *st_b, t_list **oplst)
{
	int	v1;
	int	v2;
	int	v3;

	if (is_sorted(*st_a))
		return ;
	v1 = st_a->first->value;
	v2 = st_a->first->next->value;
	v3 = st_a->last->value;
	if (v1 > v2 && v1 < v3)
		sa(st_a, st_b, oplst);
	else if (v1 > v2 && v1 > v3)
		ra(st_a, st_b, oplst);
	else
		sa(st_a, st_b, oplst);
	three_elem(st_a, st_b, oplst);
}

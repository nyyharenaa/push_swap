/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_metric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:08:36 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 14:29:27 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

float	compute_disorder(t_stack st)
{
	t_st_node	*n1;
	t_st_node	*n2;
	int			mistake;
	int			pair;

	pair = 0;
	mistake = 0;
	n1 = st.first;
	while (n1)
	{
		n2 = n1->next;
		while (n2)
		{
			pair++;
			if (n1->value > n2->value)
				mistake++;
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	if (pair)
		return ((float)mistake / pair);
	return (0);
}

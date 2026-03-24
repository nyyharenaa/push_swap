/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:39:16 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/16 13:41:37 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

t_stack	st_to_value_index(t_stack st)
{
	t_st_node	*n1;
	t_st_node	*n2;
	t_stack		nst;
	int			value;

	n1 = st.first;
	nst.first = NULL;
	nst.last = NULL;
	nst.size = 0;
	while (n1)
	{
		value = 0;
		n2 = st.first;
		while (n2)
		{
			if (n2->value < n1->value)
				value++;
			n2 = n2->next;
		}
		st_add_back(&nst, st_new(value));
		n1 = n1->next;
	}
	return (nst);
}

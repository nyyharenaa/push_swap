/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:39:16 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 23:36:08 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

void	st_to_value_index(t_stack st)
{
	t_st_node	*n1;
	t_st_node	*n2;
	int			value;

	n1 = st.first;
	while (n1)
	{
		value = 0;
		n2 = n1->next;
		while (n2)
		{
			if (n2->value < n1->value)
				value++;
			n2 = n2->next;
		}
		n1->value = value;
		n1 = n1->next;
	}
}

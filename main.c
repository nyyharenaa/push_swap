/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 21:40:51 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *st);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	int			index;
	t_list		*oplst;

	index = 1;
	init_stack(&st_a);
	init_stack(&st_b);
	while (index < ac)
	{
		node = st_new(ft_atoi(av[index]));
		st_add_back(&st_a, node);
		index++;
	}
	st_to_value_index(st_a);
	oplst = al_complex(&st_a, &st_b);
	oplst_print(oplst);
	oplst_clear(&oplst);
	st_clear(&st_a);
	st_clear(&st_b);
	return (0);
}

static void	init_stack(t_stack *st)
{
	st->first = NULL;
	st->last = NULL;
	st->size = 0;
}

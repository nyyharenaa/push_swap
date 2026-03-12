/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 10:56:11 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *st);
static void	print_stack_a_b(t_stack st_a, t_stack st_b);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	int			index;
	t_list		*oplist;

	index = 1;
	init_stack(&st_a);
	init_stack(&st_b);
	while (index < ac)
	{
		node = st_new(ft_atoi(av[index]));
		st_add_back(&st_a, node);
		index++;
	}
	oplist = al_simple(&st_a, &st_b);
	oplst_print(oplist);
	oplst_clear(&oplist);
	print_stack_a_b(st_a, st_b);
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

static void	print_stack_a_b(t_stack st_a, t_stack st_b)
{
	t_st_node	*node;

	node = st_a.first;
	ft_printf("a: ");
	while (node)
	{
		ft_printf("%i", node->value);
		node = node->next;
		if (node)
			ft_printf(" ");
	}
	ft_printf("\n");
	node = st_b.first;
	ft_printf("b: ");
	while (node)
	{
		ft_printf("%i", node->value);
		node = node->next;
		if (node)
			ft_printf(" ");
	}
	ft_printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/11 07:55:08 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inti_stack(t_stack *st);
static void	print_stack(char *st_name, t_stack st);

int	main(void)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	int			index;

	index = 0;
	inti_stack(&st_a);
	inti_stack(&st_b);
	while (index < 5)
	{
		node = st_new(++index);
		st_add_back(&st_a, node);
	}
	print_stack("a", st_a);
	print_stack("b", st_b);
	pb(&st_a, &st_b);
	print_stack("a", st_a);
	print_stack("b", st_b);
	st_clear(&st_a);
	st_clear(&st_b);
	return (0);
}

static void	inti_stack(t_stack *st)
{
	st->first = NULL;
	st->last = NULL;
	st->size = 0;
}

static void	print_stack(char *st_name, t_stack st)
{
	t_st_node	*node;

	node = st.first;
	ft_printf("%s: ", st_name);
	while (node)
	{
		ft_printf("%i", node->value);
		node = node->next;
		if (node)
			ft_printf(" ");
	}
	ft_printf("\n");
}

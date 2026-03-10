/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/10 14:37:26 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack stack);

int	main(void)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	int			index;

	index = 0;
	st_a.first = NULL;
	st_a.last = NULL;
	st_a.size = 0;
	st_b.first = NULL;
	st_b.last = NULL;
	st_b.size = 0;
	while (index < 5)
	{
		node = st_new(++index);
		st_add_back(&st_a, node);
	}
	print_stack(st_a);
	ft_putchar('\n');
	(&st_a, &st_b);
	print_stack(st_a);
	ft_putchar('\n');
	st_clear(&st_a);
	return (0);
}

static void	print_stack(t_stack stack)
{
	t_st_node	*node;

	node = stack.first;
	while (node)
	{
		ft_printf("%i", node->value);
		node = node->next;
		if (node)
			ft_printf(" ");
	}
}

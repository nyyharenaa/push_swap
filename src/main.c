/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/16 13:29:06 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	t_list		*lst_av;
	t_list		*oplist;
	t_list		*temp;

	(void)ac;
	lst_av = get_av(av);
	temp = lst_av;
	check_av(lst_av);
	check_flag(lst_av);
	ft_printf("Input values: %s\n", (char *)lst_av->content);
	init_stack(&st_a);
	init_stack(&st_b);
	lst_av = temp;
	while (lst_av)
	{
		node = st_new(ft_atoi(lst_av->content));
		st_add_back(&st_a, node);
		lst_av = lst_av->next;
	}
	ft_lstclear(&temp, free);
	ft_printf("disorder metric: %i%%\n", (int)(100 * compute_disorder(st_a)));
	oplist = al_simple(&st_a, &st_b);
	oplst_print(oplist);
	oplst_clear(&oplist);
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

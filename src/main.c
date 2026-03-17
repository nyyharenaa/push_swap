/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/17 12:01:06 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_list		*flag;
	t_list		*lst_av;
	t_list		*oplist;

	(void)ac;
	lst_av = get_av(av);
	check_av(lst_av);
	flag = check_flag(lst_av);
	ft_printf("Input values: %s\n", (char *)lst_av->content);
	init_stack(&st_a);
	init_stack(&st_b);
	fill_stack_int(&st_a, lst_av);
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

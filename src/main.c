/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 12:24:17 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		old_st_a;
	t_stack		st_b;
	t_list		*flag;
	t_list		*lst_av;
	t_list		*oplst;
	float		metric;
	t_st_node	*node;

	(void)ac;
	lst_av = get_av(av);
	check_av(lst_av);
	check_dup(lst_av);
	flag = check_flag(lst_av);
	init_stack(&st_a);
	init_stack(&st_b);
	fill_stack_int(&st_a, lst_av);
	ft_lstclear(&lst_av, free);
	while (lst_av && ft_strncmp(lst_av->content, "--", 2))
	{
		node = st_new(ft_atoi(lst_av->content));
		st_add_back(&st_a, node);
		lst_av = lst_av->next;
	}
	old_st_a = st_a;
	st_a = st_to_value_index(st_a);
	metric = compute_disorder(st_a);
	st_clear(&old_st_a);
	oplst = al_medium(&st_a, &st_b);
	optim_oplst(oplst);
	oplst_print(oplst);
	ps_bench(metric, MEDIUM, NSQRTN, oplst);
	oplst_clear(&oplst);
	st_clear(&st_a);
	st_clear(&st_b);
	ft_lstclear(&flag, free);
	return (0);
}

static void	init_stack(t_stack *st)
{
	st->first = NULL;
	st->last = NULL;
	st->size = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/13 04:44:10 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);
static t_list	*get_av(char **av);
static void		check_av(t_list *av);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	t_list		*oplst;
	t_list		*lst_av;
	t_list		*oplist;

	lst_av = get_av(av);
	check_av(&lst_av);
	while (lst_av && ft_strncmp(lst_av->content, "--", 2))
	{
		node = st_new(ft_atoi(lst_av->content));
		st_add_back(&st_a, node);
		lst_av = lst_av->next;
	}
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
	optim_oplst(oplst);
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

static t_list	*get_av(char **av)
{
	t_list	*l_av;
	char	**str_av;
	size_t	i;
	size_t	j;

	i = 1;
	l_av = NULL;
	if (av[1] == NULL)
		exit(1);
	while (av[i])
	{
		str_av = ft_split(av[i], ' ');
		j = 0;
		while (str_av[j])
			ft_lstadd_back(&l_av, ft_lstnew(str_av[j++]));
		free(str_av);
		i++;
	}
	return (l_av);
}

static void	check_av(t_list *av)
{
	t_list	*node;

	node = av;
	if (!av)
		exit(1);
	while (av)
	{
		if (!ft_isdigit(*(char *)av->content)
			&& !(ft_strncmp(av->content, "--adaptive", 10) == 0
				|| ft_strncmp(av->content, "--simple", 8) == 0
				|| ft_strncmp(av->content, "--medium", 8) == 0
				|| ft_strncmp(av->content, "--complex", 9) == 0
				|| ft_strncmp(av->content, "--bench", 7) == 0))
		{
			ft_printf("Error\n");
			ft_lstclear(&node, free);
			exit(1);
		}
		av = av->next;
	}
}

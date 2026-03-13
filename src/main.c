/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/13 10:25:20 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);
static t_list	*get_av(char **av);
static void		check_av(t_list *av);
static int	ft_isnumber(const char *str);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	t_list		*oplst;
	t_list		*lst_av;
	t_list		*oplist;
	t_list		*temp;

	(void)ac;
	lst_av = get_av(av);
	temp = lst_av;
	check_av(lst_av);
	init_stack(&st_a);
	init_stack(&st_b);
	while (lst_av && ft_strncmp(lst_av->content, "--", 2))
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
		if (!ft_isnumber((char *)av->content)
			&& !(ft_strncmp(av->content, "--adaptive", ft_strlen(av->content)) == 0
				|| ft_strncmp(av->content, "--simple", ft_strlen(av->content)) == 0
				|| ft_strncmp(av->content, "--medium", ft_strlen(av->content)) == 0
				|| ft_strncmp(av->content, "--complex", ft_strlen(av->content)) == 0
				|| ft_strncmp(av->content, "--bench", ft_strlen(av->content)) == 0))
		{
			ft_printf("Error\n");
			ft_lstclear(&node, free);
			exit(1);
		}
		av = av->next;
	}
}

static int	ft_isnumber(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

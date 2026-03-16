/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/16 15:07:55 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *st);
static t_list	*get_av(char **av);
static int		check_av(t_list *av);
static int		ft_isnumber(const char *str);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		old_st_a;
	t_stack		st_b;
	t_st_node	*node;
	t_list		*lst_av;
	t_list		*oplst;
	t_list		*temp;

	(void)ac;
	lst_av = get_av(av);
	temp = lst_av;
	if (!check_av(lst_av))
		return (1);
	init_stack(&st_a);
	init_stack(&st_b);
	while (lst_av && ft_strncmp(lst_av->content, "--", 2))
	{
		node = st_new(ft_atoi(lst_av->content));
		st_add_back(&st_a, node);
		lst_av = lst_av->next;
	}
	ft_lstclear(&temp, free);
	old_st_a = st_a;
	st_a = st_to_value_index(st_a);
	st_clear(&old_st_a);
	oplst = al_medium(&st_a, &st_b);
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

static int	check_av(t_list *av)
{
	t_list	*node;
	int		stop;

	stop = 0;
	node = av;
	if (!av)
		return (0);
	while (av && !stop)
	{
		if (!ft_isnumber((char *)av->content)
			&& !(ft_strncmp(av->content, "--adaptive", ft_strlen(av->content) + 1) == 0
				|| ft_strncmp(av->content, "--simple", ft_strlen(av->content) + 1) == 0
				|| ft_strncmp(av->content, "--medium", ft_strlen(av->content) + 1) == 0
				|| ft_strncmp(av->content, "--complex", ft_strlen(av->content) + 1) == 0
				|| ft_strncmp(av->content, "--bench", ft_strlen(av->content) + 1) == 0))
		{
			ft_printf("Error\n");
			ft_lstclear(&node, free);
			stop = 1;
		}
		av = av->next;
	}
	return (!stop);
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


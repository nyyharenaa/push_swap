/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/11 12:09:31 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inti_stack(t_stack *st);
static void	*get_cmd_function(char *cmd);
static void	handle_user_cmd(t_stack *st_a, t_stack *st_b);
static void	print_stack_a_b(t_stack st_a, t_stack st_b);

int	main(int ac, char **av)
{
	t_stack		st_a;
	t_stack		st_b;
	t_st_node	*node;
	int			index;
	int			value;

	index = 1;
	inti_stack(&st_a);
	inti_stack(&st_b);
	while (index < ac)
	{
		value = ft_atoi(av[index]);
		node = st_new(value);
		st_add_back(&st_a, node);
		index++;
	}
	handle_user_cmd(&st_a, &st_b);
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

static void	*get_cmd_function(char *cmd)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		return (sa);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		return (sb);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		return (ss);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		return (pa);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		return (pb);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		return (rra);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		return (rrb);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		return (rrr);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		return (ra);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		return (rb);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		return (rr);
	return (NULL);
}

static void	handle_user_cmd(t_stack *st_a, t_stack *st_b)
{
	void	(*func)(t_stack *, t_stack *);
	char	*line;
	char	**cmd_list;
	int		index;
	int		stop;

	stop = 0;
	while (!stop)
	{
		index = 0;
		cmd_list = NULL;
		line = get_next_line(0);
		if (line)
			cmd_list = ft_split(line, ' ');
		while (cmd_list && cmd_list[index])
		{
			func = get_cmd_function(cmd_list[index]);
			if (func)
				func(st_a, st_b);
			free(cmd_list[index++]);
		}
		print_stack_a_b(*st_a, *st_b);
		if (cmd_list)
			free(cmd_list);
		if (line)
			free(line);
		else
			stop = 1;
	}
}

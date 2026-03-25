/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:07:41 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/25 06:59:50 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		execute_funclst(t_list *funclst, t_stack *st_a, t_stack *st_b);
static void		parse_stack(char **av, t_stack *st);
static void		*get_cmdfunction(char *cmd);
static t_list	*parse_input(char *input);

int	main(int ac, char **av)
{
	char	*input;
	t_list	*funclst;
	t_stack	st_a;
	t_stack	st_b;

	(void)ac;
	input = NULL;
	funclst = NULL;
	st_b = create_stack();
	parse_stack(av, &st_a);
	input = get_next_line(0);
	while (input != NULL)
	{
		funclst = parse_input(input);
		execute_funclst(funclst, &st_a, &st_b);
		free(input);
		ft_lstclear(funclst, NULL);
		input = get_next_line(0);
	}
	if (compute_disorder(st_a) == 0)
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	return (0);
}

static void	parse_stack(char **av, t_stack *st)
{
	t_list	*arglst;
	t_list	*node;
	int		value;
	int		index;

	index = 0;
	*st = create_stack();
	arglst = get_arglst(av);
	node = arglst;
	while (node != NULL)
	{
		if (!isnumber(node->content))
			break;
		value = ft_atoi(node->content);
		st_add_back(st, st_new(value));
		node = node->next;
	}
	if (node != NULL)
		st_clear(&st);
	ft_lstclear(&arglst, free);
}

static int	execute_funclst(t_list *funclst, t_stack *st_a, t_stack *st_b)
{
	void	(*func)(t_stack *, t_stack *, t_list **);
	t_list	*node;

	node = funclst;
	while (node != NULL)
	{
		func = node->content;
		if (func)
			func(st_a, st_b, NULL);
		else
			return (0);
		node = node->next;
	}
	return (1);
}

static void *get_cmdfunction(char *cmd)
{
	if (ft_strncmp(cmd, "sa", 4))
		return (sa);
	else if (ft_strncmp(cmd, "sb", 4))
		return (sb);
	else if (ft_strncmp(cmd, "ss", 4))
		return (ss);
	else if (ft_strncmp(cmd, "pa", 4))
		return (pa);
	else if (ft_strncmp(cmd, "pb", 4))
		return (pb);
	else if (ft_strncmp(cmd, "ra", 4))
		return (ra);
	else if (ft_strncmp(cmd, "rb", 4))
		return (rb);
	else if (ft_strncmp(cmd, "rr", 4))
		return (rr);
	else if (ft_strncmp(cmd, "rra", 4))
		return (rra);
	else if (ft_strncmp(cmd, "rrb", 4))
		return (rrb);
	else if (ft_strncmp(cmd, "rrr", 4))
		return (rrr);
	return (NULL);
}

static t_list	*parse_input(char *input)
{
	char	**vstr;
	t_list	*funclst;
	t_list	*node;
	void	*func;
	int		index;

	index = 0;
	funclst = NULL;
	vstr = ft_split(input, ' ');
	while (vstr[index])
	{
		func = get_cmdfunction(vstr[index]);
		node = ft_lstnew(func);
		ft_lstadd_back(&funclst, node);
		free(vstr[index++]);
	}
	free(vstr);
	return (funclst);
}

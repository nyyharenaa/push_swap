/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:07:41 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/27 14:12:03 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		execute_funclst(t_list *funclst, t_stack *st_a, t_stack *st_b);
static int		parse_stack(char **av, t_stack *st);
static void		*get_cmdfunction(char *cmd);
static t_list	*parse_input(char *input);

static void		print_stack(t_stack st)
{
	t_st_node	*node;

	node = st.first;
	write(1, "stack: ", 8);
	while (node)
	{
		ft_dprintf(1, "%i ", node->value);
		node = node->next;
	}
	write(1, "\n", 1);
}

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
	if (!parse_stack(av, &st_a))
		return (0);
	input = get_next_line(0);
	while (input != NULL)
	{
		funclst = parse_input(input);
		execute_funclst(funclst, &st_a, &st_b);
		ft_lstclear(&funclst, NULL);
		free(input);
		input = get_next_line(0);
	}
	if (is_sorted(st_a))
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	return (0);
}

static int	parse_stack(char **av, t_stack *st)
{
	t_list	*arglst;
	t_list	*flaglst;
	int		valid;

	arglst = NULL;
	flaglst = NULL;
	*st = create_stack();
	valid = get_datalst(av, &arglst, &flaglst);
	valid = valid & check_flag(flaglst);
	valid = valid & check_arg(arglst);
	if (valid && (flaglst == NULL))
		fill_stack(st, arglst);
	else
		ft_dprintf(2, "Error\n");
	ft_lstclear(&flaglst, free);
	ft_lstclear(&arglst, free);
	return (valid && (flaglst == NULL));
}

static int	execute_funclst(t_list *funclst, t_stack *st_a, t_stack *st_b)
{
	void		(*func)(t_stack *, t_stack *, t_list **);
	t_list		*node;

	node = funclst;
	while (node != NULL)
	{
		func = node->content;
		if (func)
			func(st_a, st_b, NULL);
		else
			return (0);
		print_stack(*st_a);
		node = node->next;
	}
	return (1);
}

static void	*get_cmdfunction(char *cmd)
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
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		return (ra);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		return (rb);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		return (rr);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		return (rra);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		return (rrb);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
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

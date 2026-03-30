/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:30:04 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/30 14:14:10 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		pick_algo(int *optflag, float metric);
static t_list	*execute_algo(t_stack *st_a, t_stack *st_b, int optflag);
static int		parse_stack(char **av, t_stack *st, int *optflag);

int	main(int ac, char **av)
{
	t_stack	st_a;
	t_stack	st_b;
	t_list	*oplst;
	int		optflag;
	float	metric;

	(void)ac;
	oplst = NULL;
	st_b = create_stack();
	if (parse_stack(av, &st_a, &optflag))
	{
		metric = compute_disorder(st_a);
		if (opt_get_strategy(optflag) == STRGT_ADAPTIVE)
			pick_algo(&optflag, metric);
		if (!is_sorted(st_a))
			oplst = execute_algo(&st_a, &st_b, optflag);
		oplst_print(oplst);
		if (opt_get_bench(optflag))
			ps_bench(metric, optflag, oplst);
		if (oplst)
			oplst_clear(&oplst);
		st_clear(&st_a);
		st_clear(&st_b);
	}
	return (0);
}

static int	parse_stack(char **av, t_stack *st, int *optflag)
{
	t_list	*arglst;
	t_list	*flaglst;
	t_stack	sttmp;
	int		valid;

	flaglst = NULL;
	arglst = NULL;
	*st = create_stack();
	valid = get_datalst(av, &arglst, &flaglst);
	valid = valid && check_flag(flaglst);
	valid = valid && check_arg(arglst);
	if (valid)
	{
		fill_stack(st, arglst);
		*optflag = parse_flag(flaglst);
		sttmp = normalize(*st);
		st_clear(st);
		*st = sttmp;
	}
	else
		ft_dprintf(2, "Error\n");
	ft_lstclear(&arglst, free);
	ft_lstclear(&flaglst, free);
	return (valid);
}

static t_list	*execute_algo(t_stack *st_a, t_stack *st_b, int optflag)
{
	t_list	*oplst;

	oplst = NULL;
	if (st_a->size <= 5 && opt_get_strategy(optflag) == STRGT_ADAPTIVE)
		oplst = al_special_case(st_a, st_b);
	else if (opt_get_complexity(optflag) == CMPLX_SQRN)
		oplst = al_simple(st_a, st_b);
	else if (opt_get_complexity(optflag) == CMPLX_NSQRTN)
		oplst = al_medium(st_a, st_b);
	else if (opt_get_complexity(optflag) == CMPLX_NLOGN)
		oplst = al_complex(st_a, st_b);
	return (oplst);
}

static void	pick_algo(int *optflag, float metric)
{
	if (opt_get_strategy(*optflag) != STRGT_ADAPTIVE)
		return ;
	*optflag = *optflag & ~(CMPLX_SQRN | CMPLX_NSQRTN | CMPLX_NLOGN);
	if (metric < 0.2)
		*optflag = *optflag | CMPLX_SQRN;
	else if (metric < 0.5)
		*optflag = *optflag | CMPLX_NSQRTN;
	else
		*optflag = *optflag | CMPLX_NLOGN;
}

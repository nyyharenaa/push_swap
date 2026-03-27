/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:38:29 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/27 14:53:36 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bench.h"

static const char	*get_strategy_detail(int optflag);

void	ps_bench(float metric, int optflag, t_list *oplst)
{
	ft_dprintf(2, "[bench] disorder:  %f%%\n",
		metric * 100);
	ft_dprintf(2, "[bench] strategy:  %s\n",
		get_strategy_detail(optflag));
	ft_dprintf(2, "[bench] total_ops:  %i\n",
		ft_lstsize(oplst));
	ft_dprintf(2, "[bench] sa:  %i  sb:  %i  pa:  %i  pb:  %i\n",
		oplst_count(oplst, "sa"), oplst_count(oplst, "sb"),
		oplst_count(oplst, "pa"), oplst_count(oplst, "pb"));
	ft_dprintf(2, "[bench] ra:  %i  rb:  %i  "
		"rr:  %i  rra:  %i  rrb:  %i  rrr:  %i\n",
		oplst_count(oplst, "ra"), oplst_count(oplst, "rb"),
		oplst_count(oplst, "rr"), oplst_count(oplst, "rra"),
		oplst_count(oplst, "rrb"), oplst_count(oplst, "rrr"));
}

static const char	*get_strategy_detail(int optflag)
{
	if (opt_get_strategy(optflag) == STRGT_SIMPLE)
		return ("Simple / O(n²)");
	if (opt_get_strategy(optflag) == STRGT_MEDIUM)
		return ("Medium / O(n√n)");
	if (opt_get_strategy(optflag) == STRGT_COMPLEX)
		return ("Complex / O(n log n)");
	if (opt_get_strategy(optflag) == STRGT_ADAPTIVE)
	{
		if (opt_get_complexity(optflag) == CMPLX_SQRN)
			return ("Adaptive / O(n²)");
		if (opt_get_complexity(optflag) == CMPLX_NSQRTN)
			return ("Adaptive / O(n√n)");
		if (opt_get_complexity(optflag) == CMPLX_NLOGN)
			return ("Adaptive / O(n log n)");
	}
	return ("");
}

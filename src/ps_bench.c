/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:38:29 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/17 05:51:17 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bench.h"

static const char	*get_strategy_detail(int strgt, int cplxt);

void	ps_bench(float metric, int strgt, int cplxt, t_list *oplst)
{
	ft_printf("[bench] disorder: %i.%i%%\n",
			(int)(metric * 100),
			((int)(metric * 10000) % 100));
	ft_printf("[bench] strategy: %s\n",
			get_strategy_detail(strgt, cplxt));
	ft_printf("[bench] total_ops: %i\n",
			ft_lstsize(oplst));
	ft_printf("[bench] sa: %i sb: %i pa: %i pb: %i\n",
			oplst_count(oplst, "sa"), oplst_count(oplst, "sb"),
			oplst_count(oplst, "pa"), oplst_count(oplst, "pb"));
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
			oplst_count(oplst, "ra"), oplst_count(oplst, "rb"),
			oplst_count(oplst, "rr"), oplst_count(oplst, "rra"),
			oplst_count(oplst, "rrb"), oplst_count(oplst, "rrr"));
}

static const char	*get_strategy_detail(int strgt, int cplxt)
{
	if (strgt == SIMPLE)
		return ("Simple / O(n²)");
	if (strgt == MEDIUM)
		return ("Medium / O(n√n)");
	if (strgt == COMPLEX)
		return ("Complex / O(n log n)");
	if (strgt == ADAPTIVE)
	{
		if (cplxt == SQRN)
			return ("Adaptive / O(n²)");
		if (cplxt == SQRN)
			return ("Adaptive / O(n√n)");
		if (cplxt == SQRN)
			return ("Adaptive / O(n log n)");
	}
	return ("");
}


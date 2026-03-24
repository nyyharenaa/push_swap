/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bench.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 05:41:22 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/17 05:50:24 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BENCH_H
# define PS_BENCH_H

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

# define SQRN 1
# define NSQRTN 2
# define NLOGN 3

# include "libft.h"
# include "ps_oplist.h"

void	ps_bench(float metric, int strgt, int cplxt, t_list *oplst);

#endif

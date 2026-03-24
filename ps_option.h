/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:58:54 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 20:17:08 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPTION_H
# define PS_OPTION_H

# define OPT_BENCH 4

# define STRGT_ADAPTIVE 0
# define STRGT_SIMPLE 1
# define STRGT_MEDIUM 2
# define STRGT_COMPLEX 3

# define CMPLX_SQRN 0
# define CMPLX_NSQRTN 8
# define CMPLX_NLOGN 16

int	opt_get_bench(int optflag);
int	opt_get_strategy(int optflag);
int	opt_get_complexity(int optflag);

#endif

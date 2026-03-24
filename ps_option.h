/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:58:54 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:24:42 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPTION_H
# define PS_OPTION_H

# define OPT_BENCH (1 << 2)

# define STRGT_ADAPTIVE (0 << 0)
# define STRGT_SIMPLE (1 << 0)
# define STRGT_MEDIUM (1 << 1)
# define STRGT_COMPLEX (3 << 0)

# define CMPLX_SQRN (0 << 3)
# define CMPLX_NSQRTN (1 << 3)
# define CMPLX_NLOGN (1 << 4)

int	opt_get_bench(int optflag);
int	opt_get_strategy(int optflag);
int	opt_get_complexity(int optflag);

#endif

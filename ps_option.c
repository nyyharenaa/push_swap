/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:10:54 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:00:02 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_option.h"

int	opt_get_bench(int optflag)
{
	return (optflag & (1 << 2));
}

int	opt_get_strategy(int optflag)
{
	return (optflag & (3 << 0));
}

int	opt_get_complexity(int optflag)
{
	return (optflag & (3 << 3));
}

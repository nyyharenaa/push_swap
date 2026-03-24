/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:56:21 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/16 13:40:53 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_ALGORITHM_H
# define PS_ALGORITHM_H

# include <limits.h>

# include "libft.h"
# include "ps_stack.h"
# include "ps_oplist.h"
# include "ps_operation.h"

float	compute_disorder(t_stack st);
t_stack	st_to_value_index(t_stack st);
void	optim_oplst(t_list *oplst);
t_list	*al_simple(t_stack *st_a, t_stack *st_b);
t_list	*al_medium(t_stack *st_a, t_stack *st_b);
t_list	*al_complex(t_stack *st_a, t_stack *st_b);

#endif

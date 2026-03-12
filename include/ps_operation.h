/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:53:06 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 21:38:01 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPERATION_H
# define PS_OPERATION_H

# include "ps_stack.h"
# include "ps_oplist.h"

void	sa(t_stack *a, t_stack *b, t_list **oplst);
void	sb(t_stack *a, t_stack *b, t_list **oplst);
void	ss(t_stack *a, t_stack *b, t_list **oplst);
void	pa(t_stack *a, t_stack *b, t_list **oplst);
void	pb(t_stack *a, t_stack *b, t_list **oplst);
void	ra(t_stack *a, t_stack *b, t_list **oplst);
void	rb(t_stack *a, t_stack *b, t_list **oplst);
void	rr(t_stack *a, t_stack *b, t_list **oplst);
void	rra(t_stack *a, t_stack *b, t_list **oplst);
void	rrb(t_stack *a, t_stack *b, t_list **oplst);
void	rrr(t_stack *a, t_stack *b, t_list **oplst);

#endif

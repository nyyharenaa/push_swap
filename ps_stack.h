/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:51:13 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/11 12:09:27 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <stdlib.h>

typedef struct s_st_node
{
	int					value;
	struct s_st_node	*next;
}				t_st_node;

typedef struct s_stack
{
	t_st_node	*first;
	t_st_node	*last;
	size_t		size;
}				t_stack;

t_st_node	*st_new(int val);
t_st_node	*st_second_last(t_stack stack);
void		st_add_front(t_stack *stack, t_st_node *node);
void		st_add_back(t_stack *stack, t_st_node *node);
void		st_clear(t_stack *stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:13:35 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/27 09:22:22 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

t_st_node	*st_new(long val)
{
	t_st_node	*node;

	node = malloc(sizeof(t_st_node));
	if (!node)
		return (NULL);
	node->value = val;
	node->next = NULL;
	return (node);
}

t_st_node	*st_second_last(t_stack stack)
{
	t_st_node	*current;

	if (stack.size < 2)
		return (NULL);
	current = stack.first;
	while (current->next->next)
		current = current->next;
	return (current);
}

void	st_add_front(t_stack *stack, t_st_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->first;
	stack->first = node;
	if (!stack->last)
		stack->last = stack->first;
	stack->size++;
}

void	st_add_back(t_stack *stack, t_st_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->last)
		stack->last->next = node;
	stack->last = node;
	if (!stack->first)
		stack->first = stack->last;
	stack->last->next = NULL;
	stack->size++;
}

void	st_clear(t_stack *stack)
{
	t_st_node	*current;
	t_st_node	*next;

	if (!stack)
		return ;
	current = stack->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

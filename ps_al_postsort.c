/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_al_postsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:54:40 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 12:19:30 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_algorithm.h"

static int	is_inverse(t_list *a, t_list *b);

void	optim_oplst(t_list *oplst)
{
	t_list	*node;

	if (!oplst || !oplst->next || !oplst->next->next)
		return ;
	optim_oplst(oplst->next);
	if (!oplst->next->next)
		return ;
	if (is_inverse(oplst->next, oplst->next->next)
		|| is_inverse(oplst->next->next, oplst->next))
	{
		node = oplst->next->next;
		oplst->next->next = node->next;
		ft_lstdelone(node, NULL);
		node = oplst->next;
		oplst->next = node->next;
		ft_lstdelone(node, NULL);
	}
}

static int	is_inverse(t_list *a, t_list *b)
{
	if (!ft_strncmp(a->content, "sa", 2) && !ft_strncmp(b->content, "sa", 3))
		return (1);
	if (!ft_strncmp(a->content, "sb", 2) && !ft_strncmp(b->content, "sb", 3))
		return (1);
	if (!ft_strncmp(a->content, "ra", 2) && !ft_strncmp(b->content, "rra", 3))
		return (1);
	if (!ft_strncmp(a->content, "rb", 2) && !ft_strncmp(b->content, "rrb", 3))
		return (1);
	if (!ft_strncmp(a->content, "pa", 2) && !ft_strncmp(b->content, "pb", 2))
		return (1);
	return (0);
}

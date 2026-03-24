/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:50:17 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 17:57:16 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parser.h"

t_list	*get_arglst(char **av)
{
	t_list	*arglst;
	char	**str_av;
	size_t	i;
	size_t	j;

	i = 1;
	arglst = NULL;
	if (av[1] == NULL)
		exit(1);
	while (av[i])
	{
		str_av = ft_split(av[i], ' ');
		j = 0;
		while (str_av[j])
			ft_lstadd_back(&arglst, ft_lstnew(str_av[j++]));
		free(str_av);
		i++;
	}
	return (arglst);
}

void	check_arglst(t_list *arglst)
{
	t_list	*node;

	node = arglst;
	if (!arglst)
		exit(1);
	while (arglst)
	{
		if (!isnumber((char *)arglst->content)
			&& !(ft_strncmp(arglst->content, "--adaptive", 11) == 0
				|| ft_strncmp(arglst->content, "--simple", 9) == 0
				|| ft_strncmp(arglst->content, "--medium", 9) == 0
				|| ft_strncmp(arglst->content, "--complex", 10) == 0
				|| ft_strncmp(arglst->content, "--bench", 8) == 0))
		{
			ft_dprintf(2, "Error\n");
			ft_lstclear(&node, free);
			exit(1);
		}
		arglst = arglst->next;
	}
}

t_list	*extract_flag(t_list *arglst)
{
	t_list	*node;
	t_list	*flaglst;

	flaglst = NULL;
	node = arglst;
	while (node)
	{
		if (ft_strncmp(node->content, "--", 2) == 0)
			ft_lstadd_back(&flaglst, ft_lstnew(ft_strdup(node->content)));
		node = node->next;
	}
	if (ft_lstsize(flaglst) > 2
		|| (ft_lstsize(flaglst) == 2 && ft_lstchr(flaglst, "--bench") == NULL))
	{
		ft_dprintf(2, "Error\n");
		ft_lstclear(&arglst, free);
		ft_lstclear(&flaglst, free);
		exit(1);
	}
	return (flaglst);
}

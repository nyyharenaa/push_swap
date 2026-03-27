/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:50:17 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/27 11:31:42 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parser.h"

#define STR_I_MIN "-2147483648"
#define STR_I_MAX "2147483647"

static int	check_repeat(t_list *lst);

int	get_datalst(char **av, t_list **arglst, t_list **flaglst)
{
	char	**str_av;
	int		valid;
	size_t	i;
	size_t	j;

	i = 1;
	valid = 1;
	while (av[i])
	{
		j = 0;
		str_av = ft_split(av[i], ' ');
		while (str_av[j])
		{
			if (ft_strncmp(str_av[j], "--", 2) == 0)
				ft_lstadd_back(flaglst, ft_lstnew(ft_strdup(str_av[j])));
			else if (isnumber(str_av[j]))
				ft_lstadd_back(arglst, ft_lstnew(ft_strdup(str_av[j])));
			else
				valid = 0;
			free(str_av[j++]);
		}
		free(str_av);
		i++;
	}
	return (valid);
}

int	check_flag(t_list *flaglst)
{
	int		valid;
	int		has_strgt;
	char	*str;

	valid = 1;
	has_strgt = 0;
	valid = check_repeat(flaglst);
	while (valid && flaglst)
	{
		str = flaglst->content;
		if (ft_strncmp(str, "--bench", 8) != 0)
		{
			if (!has_strgt
				&& (ft_strncmp(str, "--simple", 7) == 0
					|| ft_strncmp(str, "--medium", 9) == 0
					|| ft_strncmp(str, "--complex", 10) == 0
					|| ft_strncmp(str, "--adaptive", 11) == 0))
				has_strgt = 1;
			else
				valid = 0;
		}
		flaglst = flaglst->next;
	}
	return (valid);
}

int	check_arg(t_list *arglst)
{
	char	*str;
	int		valid;

	valid = 1;
	valid = check_repeat(arglst);
	while (valid && arglst)
	{
		str = arglst->content;
		if (!isnumber(str))
			valid = 0;
		else if (ft_strlen(str) > (ft_strlen(STR_I_MAX) + (str[0] == '-')))
			valid = 0;
		else if (ft_strlen(str) == (ft_strlen(STR_I_MAX) + (str[0] == '-')))
		{
			if (str[0] == '-' && ft_strncmp(str, STR_I_MIN, 12) > 0)
				valid = 0;
			else if (str[0] != '-' && ft_strncmp(str, STR_I_MAX, 11) > 0)
				valid = 0;
		}
		arglst = arglst->next;
	}
	return (valid);
}

static int	check_repeat(t_list *lst)
{
	t_list	*node;
	char	*str;
	int		valid;

	valid = 1;
	node = lst;
	while (valid && node)
	{
		str = node->content;
		if (lstchr(node->next, str) != NULL)
			valid = 0;
		node = node->next;
	}
	return (valid);
}

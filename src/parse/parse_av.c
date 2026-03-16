/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:50:17 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/16 17:00:27 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_isnumber(const char *str);
static t_list	*ft_lstchr(t_list *lst, void *content);

t_list	*get_av(char **av)
{
	t_list	*l_av;
	char	**str_av;
	size_t	i;
	size_t	j;

	i = 1;
	l_av = NULL;
	if (av[1] == NULL)
		exit(1);
	while (av[i])
	{
		str_av = ft_split(av[i], ' ');
		j = 0;
		while (str_av[j])
			ft_lstadd_back(&l_av, ft_lstnew(str_av[j++]));
		free(str_av);
		i++;
	}
	return (l_av);
}

void	check_av(t_list *av)
{
	t_list	*node;

	node = av;
	if (!av)
		exit(1);
	while (av)
	{
		if (!ft_isnumber((char *)av->content)
			&& !(ft_strncmp(av->content, "--adaptive", 11) == 0
				|| ft_strncmp(av->content, "--simple", 9) == 0
				|| ft_strncmp(av->content, "--medium", 9) == 0
				|| ft_strncmp(av->content, "--complex", 10) == 0
				|| ft_strncmp(av->content, "--bench", 8) == 0))
		{
			ft_printf("Error\n");
			ft_lstclear(&node, free);
			exit(1);
		}
		av = av->next;
	}
}

void	check_flag(t_list *av)
{
	t_list	*flag;

	flag = NULL;
	while (av)
	{
		if (ft_strncmp(av->content, "--", 2) == 0
			&& ft_lstchr(flag, av->content))
		{
			ft_printf("Error\n");
			ft_lstclear(&av, free);
			ft_lstclear(&flag, free);
			exit(1);
		}
		if (ft_strncmp(av->content, "--", 2) == 0)
			ft_lstadd_back(&flag, ft_lstnew(av->content));
		av = av->next;
	}
	if (ft_lstsize(flag) > 2 || ft_lstchr(flag, "--bench") == NULL)
	{
		ft_printf("Error\n");
		ft_lstclear(&av, free);
		ft_lstclear(&flag, free);
		exit(1);
	}
}

static	int	ft_isnumber(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static t_list	*ft_lstchr(t_list *lst, void *content)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, content, ft_strlen(content) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

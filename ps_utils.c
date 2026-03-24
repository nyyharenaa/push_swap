/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:28:22 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:15:08 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stack	create_stack()
{
	t_stack	st;

	st.first = NULL;
	st.last = NULL;
	st.size = 0;
	return (st);
}

int	isnumber(const char *str)
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

t_list	*ft_lstchr(t_list *lst, void *content)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, content, ft_strlen(content) + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	fill_stack(t_stack *stack, t_list *lst)
{
	t_list		*temp;
	t_st_node	*node;

	temp = lst;
	while (lst)
	{
		if (isnumber((char *)lst->content))
		{
			node = st_new(ft_atoi((char *)lst->content));
			st_add_back(stack, node);
		}
		lst = lst->next;
	}
}

int		parse_flag(t_list *flaglst)
{
	int	optflag;

	optflag = 0;
	if (ft_lstchr(flaglst, "--bench"))
		optflag = optflag | OPT_BENCH;
	if (ft_lstchr(flaglst, "--simple"))
		optflag = optflag | STRGT_SIMPLE | CMPLX_SQRN;
	else if (ft_lstchr(flaglst, "--medium"))
		optflag = optflag | STRGT_MEDIUM | CMPLX_NSQRTN;
	else if (ft_lstchr(flaglst, "--complex"))
		optflag = optflag | STRGT_COMPLEX | CMPLX_NLOGN;
	return (optflag);
}

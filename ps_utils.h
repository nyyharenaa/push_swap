/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:31:35 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 19:01:11 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

#include "libft.h"
#include "ps_stack.h"
# include "ps_option.h"

t_stack	create_stack();
int		isnumber(const char *str);
t_list	*ft_lstchr(t_list *lst, void *content);
void	fill_stack(t_stack *stack, t_list *lst);
int		parse_flag(t_list *flaglst);

#endif
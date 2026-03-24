/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:47 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 12:31:39 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSER_H
# define PS_PARSER_H

# include "libft.h"
# include "ps_stack.h"

int		ft_isnumber(const char *str);
t_list	*ft_lstchr(t_list *lst, void *content);
void	check_dup(t_list *av);
void	free_tab(char **tab);

void	fill_stack_int(t_stack *stack, t_list *lst);

t_list	*get_av(char **av);
void	check_av(t_list *av);
t_list	*check_flag(t_list *av);

#endif
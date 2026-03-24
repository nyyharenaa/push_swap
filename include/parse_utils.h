/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:47 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 10:38:49 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "push_swap.h"

int		ft_isnumber(const char *str);
t_list	*ft_lstchr(t_list *lst, void *content);
void	check_dup(t_list *av);
void	free_tab(char **tab);

#endif

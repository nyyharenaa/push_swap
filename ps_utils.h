/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:31:35 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/24 16:55:41 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

#include "libft.h"
#include "ps_stack.h"

t_stack	create_stack();
int		isnumber(const char *str);
void	fill_stack(t_stack *stack, t_list *lst);

#endif
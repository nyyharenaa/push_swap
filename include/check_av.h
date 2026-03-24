/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:51:19 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 10:37:18 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_AV_H
# define CHECK_AV_H

# include "push_swap.h"

t_list	*get_av(char **av);
void	check_av(t_list *av);
t_list	*check_flag(t_list *av);

#endif

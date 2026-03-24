/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oplist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:59:31 by todina-r          #+#    #+#             */
/*   Updated: 2026/03/12 10:10:04 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPLIST_H
# define PS_OPLIST_H

# include "libft.h"

void	oplst_add(t_list **lst, char *op);
void	oplst_clear(t_list **lst);
int		oplst_print(t_list *lst);
int		oplst_count(t_list *lst, char *op);

#endif

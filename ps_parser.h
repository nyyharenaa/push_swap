/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:47 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/27 11:20:40 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSER_H
# define PS_PARSER_H

# include "libft.h"
# include "ps_stack.h"
# include "ps_utils.h"

int	get_datalst(char **av, t_list **arglst, t_list **flaglst);
int	check_flag(t_list *flaglst);
int	check_arg(t_list *flaglst);

#endif
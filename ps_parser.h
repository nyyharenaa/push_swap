/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: todina-r <todina-r@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:47 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/24 19:01:02 by todina-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSER_H
# define PS_PARSER_H

# include "libft.h"
# include "ps_stack.h"
# include "ps_utils.h"

t_list	*get_arglst(char **av);
void	check_arglst(t_list *arglst);
t_list	*extract_flag(t_list *flag);

#endif
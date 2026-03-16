/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:51:19 by ny-handr          #+#    #+#             */
/*   Updated: 2026/03/16 11:41:35 by ny-handr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_AV_H
# define PARSE_AV_H

# include "libft.h"

t_list	*get_av(char **av);
void	check_av(t_list *av);
void	check_flag(t_list *av);

#endif

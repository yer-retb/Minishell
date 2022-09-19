/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 06:08:50 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_NODES_H
# define INIT_NODES_H

typedef struct n_parser
{
	t_token			*token_struct;
	struct n_parser	*next_token;
}	t_parser;

void		add_list_at_back(t_parser **head, t_parser *node);

t_parser	*init_node(t_token *token);

#endif

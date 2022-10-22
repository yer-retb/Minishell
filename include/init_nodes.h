/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/21 15:29:09 by enja             ###   ########.fr       */
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

t_psr		*init_node2(t_tkn *token);

void		add_list_at_back2(t_psr **save, t_psr *node);

#endif

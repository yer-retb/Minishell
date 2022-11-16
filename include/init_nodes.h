/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:58:26 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:58:28 by yer-retb         ###   ########.fr       */
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

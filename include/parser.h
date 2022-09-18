/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 05:07:52 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct n_parser
{
	t_token			*token_struct;
	struct n_parser	*next_token;
}	t_parser;

t_parser	*add_list_at_back(t_parser *head, t_parser *node);

t_parser	*init_node(t_token *token);

#endif
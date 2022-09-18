/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:06:14 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 05:12:17 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_parser	*init_node(t_token *token)
{
	t_parser	*token_st;

	token_st = malloc(sizeof(t_parser));
	if (token_st == NULL)
		return (NULL);
	token_st->token_struct = token;
	token_st->next_token = NULL;
	return (token_st);
}

t_parser	*add_list_at_back(t_parser *head, t_parser *node)
{
	t_parser	*save;

	save = head;
	if (head == NULL)
		return (NULL);
	while (head->next_token)
		head = head->next_token;
	head->next_token = node;
	node->next_token = NULL;
	return (save);
}

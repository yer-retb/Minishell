/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:06:14 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 09:50:59 by ky05h1n          ###   ########.fr       */
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

void	add_list_at_back(t_parser **save, t_parser *node)
{
	t_parser	*head;

	head = *save;
	if (head == NULL)
	{
		*save = node;
		return ;
	}
	while (head->next_token)
	{
		head = head->next_token;
	}
	head->next_token = node;
	node->next_token = NULL;
}

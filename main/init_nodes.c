/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:00:53 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 07:00:54 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_parser	*init_node(t_token *token)
{
	t_parser	*token_st;

	token_st = ft_malloc(sizeof(t_parser));
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

t_psr	*init_node2(t_tkn *token)
{
	t_psr	*token_st;

	token_st = ft_malloc(sizeof(t_psr));
	if (token_st == NULL)
		return (NULL);
	token_st->tkn_st = token;
	token_st->nx_tkn = NULL;
	return (token_st);
}

void	add_list_at_back2(t_psr **save, t_psr *node)
{
	t_psr	*head;

	head = *save;
	if (head == NULL)
	{
		*save = node;
		return ;
	}
	while (head->nx_tkn)
		head = head->nx_tkn;
	head->nx_tkn = node;
	node->nx_tkn = NULL;
}

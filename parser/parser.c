/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:04:15 by enja              #+#    #+#             */
/*   Updated: 2022/09/20 06:14:24 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	parser_check_syntax(t_parser *head)
{
	while (head)
	{
		if (head->token_struct->e_type == TOKEN_STR)
		{
			if (head->next_token)
				head = head->next_token;
			else
				return ;
		}
		if (head->token_struct->e_type != TOKEN_STR)
		{
			if (head->next_token && head->token_struct->e_type == TOKEN_PIPE)
				head = head->next_token;
			else if (head->next_token
				&& head->next_token->token_struct->e_type == 3)
				head = head->next_token;
			else if (head->next_token && head->next_token->token_struct->e_type
				== TOKEN_STR)
				head = head->next_token;
			else
				msg_syntax_error(head->token_struct->value);
		}
	}
}

void	parser_get(t_parser *st_list)
{
	if (!st_list)
		return ;
	if (st_list->token_struct->e_type == TOKEN_PIPE)
		msg_syntax_error(st_list->token_struct->value);
	parser_check_syntax(st_list);
}

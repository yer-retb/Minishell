/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:04:15 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 10:25:22 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	parser_check_command(t_token *st_list)
{
	// printf("%s\n", st_list->value);
	if (ft_strcmp(st_list->value, "echo") != 0)
		msg_cmd_error(st_list->value);
}

void	parser_scan_cmd(t_token *st_list)
{
	if (st_list->e_type == TOKEN_STR)
		parser_check_command(st_list);
}

void	parser_get(t_parser *st_list)
{
	t_parser	*head;

	head = st_list;
	while (head)
	{
		parser_scan_cmd(head->token_struct);
		head = head->next_token;
	}
}

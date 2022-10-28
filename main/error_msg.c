/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:44:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/22 00:50:58 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	*msg_error1(void)
{
	printf("minishell : syntax error\n");
	exit_val = 2;
	return (NULL);
}

t_token	*msg_error(int e_type, char *val, char *value)
{
	t_token	*token;

	printf("minishell : syntax error\n");
	exit_val = 2;
	free(value);
	token = malloc(sizeof(t_token));
	token->e_type = e_type;
	token->value = val;
	return (token);
}

void	*msg_cmd_error(char *msg)
{
	printf("%s : command not found\n", msg);
	exit_val = 127;
	return (NULL);
}

void	*msg_syntax_error(char *msg)
{
	printf("minishell: syntax error near unexpected token `%s'\n", msg);
	exit_val = 2;
	return (NULL);
}

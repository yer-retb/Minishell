/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:00:39 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 07:00:40 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	*msg_error1(void)
{
	printf("minishell : syntax error\n");
	g_b.exit_val = 258;
	return (NULL);
}

t_token	*msg_error(int e_type, char *val, char *value)
{
	t_token	*token;

	printf("minishell : syntax error\n");
	g_b.exit_val = 258;
	free(value);
	token = ft_malloc(sizeof(t_token));
	token->e_type = e_type;
	token->value = val;
	return (token);
}

void	*msg_cmd_error(char *msg)
{
	printf("%s : command not found\n", msg);
	g_b.exit_val = 127;
	return (NULL);
}

void	*msg_syntax_error(char *msg)
{
	printf("minishell: syntax error near unexpected token `%s'\n", msg);
	g_b.exit_val = 258;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:44:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 23:55:52 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	msg_error(void)
{
	printf("minishell : syntax error\n");
	exit(1);
}

void	msg_cmd_error(char *msg)
{
	printf("%s : command not found\n", msg);
	exit(1);
}

void	msg_syntax_error(char *msg)
{
	printf("minishell: syntax error near unexpected token `%s'\n", msg);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:44:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 06:09:07 by enja             ###   ########.fr       */
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



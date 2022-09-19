/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:44:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 09:50:51 by ky05h1n          ###   ########.fr       */
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

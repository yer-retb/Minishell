/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:42:36 by enja              #+#    #+#             */
/*   Updated: 2022/09/17 01:52:05 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void	clear_prompt(void)
{
	static int	sig;
	const char	*clear_ansi;

	sig = 1;
	if (sig)
	{
		clear_ansi = "\e[1;1H\e[2J";
		write(1, clear_ansi, 11);
		sig = 0;
	}
}

char	*get_prompt(void)
{
	char	*cmd;

	clear_prompt();
	cmd = readline("[ minishell ]~> ");
	return (cmd);
}

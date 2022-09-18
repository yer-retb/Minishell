/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:42:36 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 02:11:07 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	clear_prompt(void)
{
	const char	*clear_ansi;

	clear_ansi = "\e[1;1H\e[2J";
	write(1, clear_ansi, 11);
}

char	*get_prompt(void)
{
	char		*cmd;
	static int	sig = 1;

	if (sig == 1)
	{
		clear_prompt();
		sig = 0;
	}
	cmd = readline("\033[0;32m[\033[0m minishell \033[0;32m]~>\033[0m ");
	return (cmd);
}

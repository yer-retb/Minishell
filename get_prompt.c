/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:42:36 by enja              #+#    #+#             */
/*   Updated: 2022/09/15 02:04:12 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_prompt(void)
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

int	main(int ac, char **av)
{
	char	*cmd;
	int		i;
	char	**full_line;
	// char	d = '"';
	// printf("%c", d);
	// exit(1);
	i = 0;
	(void)ac;
	(void)av;
	get_prompt();
	cmd = readline("[ minishell ]~> ");
	full_line = ft_split(cmd, ' ');
	while (full_line[i])
		printf("---> %s\n", full_line[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:00:45 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:09:53 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*get_prompt(void)
{
	char		*cmd;

	if (g_b.sg_hd == -1)
	{
		g_b.sg_hd = 0;
		dup2(g_b.saved, 0);
	}
	cmd = readline("\033[0;32m[\033[0m Minishell \033[0;32m]~>\033[0m ");
	add_history(cmd);
	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:19:23 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/18 01:33:09 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	int_sig(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	quit_sig(void)
{
	rl_on_new_line();
	rl_redisplay();
}

void	sig_handler(int sig)
{
	if (g_b.id != 0)
	{
		if (kill(g_b.id, SIGINT) == 0)
		{
			if (sig == SIGQUIT)
			{
				printf("Quit: 3\n");
				g_b.exit_val = 131;
			}
			if (sig == SIGINT)
			{
				printf("\n");
				g_b.exit_val = 130;
			}
		}
		else if (sig == SIGQUIT)
			quit_sig();
		else if (sig == SIGINT)
			int_sig();
	}
	else if (sig == SIGQUIT && g_b.id == 0)
		quit_sig();
	else if (sig == SIGINT && g_b.id == 0)
		int_sig();
}

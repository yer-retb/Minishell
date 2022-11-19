/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:39:38 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	*ft_malloc(int size)
{
	void	*tmp;

	tmp = malloc(size);
	g_b.save[g_b.index] = tmp;
	g_b.index++;
	return (tmp);
}

void	ft_signal(void)
{
	if (g_b.sg_hd == -1)
		signal (SIGCHLD, sig_handler);
	else
	{
		signal (SIGQUIT, sig_handler);
		signal (SIGINT, sig_handler);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*last_env;

	g_b.is = 0;
	(void) ac;
	(void) av;
	g_b.index = 0;
	g_b.my_env = NULL;
	ft_signal();
	last_env = envirement_list(env);
	init_shell(last_env);
}

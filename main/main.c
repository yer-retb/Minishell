/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/13 16:34:45 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	*save_malloc(int size)
{
	void	*tmp;

	tmp = malloc(size);
	g_b.save[g_b.index] = tmp;
	g_b.index++;
	return (tmp);
}

int	main(int ac, char **av, char **env)
{
	// signal(SIGQUIT,SIG_IGN);
	// signal(SIGINT,SIG_IGN);
	t_env		*last_env;

	(void) ac;
	(void) av;
	g_b.index = 0;
	g_b.my_env = NULL;
	last_env = envirement_list(env);
	init_shell(last_env);
}

// echo "| ls"
// echo "               "'$HOME'"$PATH"'$USER'
// echo ls > $P
// echo "'$USER'"'$USER'"'''$USER"
// echo $"HOME" = HOME
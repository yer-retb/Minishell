/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 05:45:49 by yer-retb         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	t_env	*last_env;

	(void) ac;
	(void) av;
	g_b.index = 0;
	g_b.my_env = NULL;
	last_env = envirement_list(env);
	init_shell(last_env);
}

// signal (SIGQUIT, SIG_IGN);
// signal (SIGINT, SIG_IGN);

// echo "| ls"
// echo "               "'$HOME'"$PATH"'$USER'
// echo ls > $P
// echo "'$USER'"'$USER'"'''$USER"
// echo $"HOME" = HOME
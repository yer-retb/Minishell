/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 03:34:44 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:39:16 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	error(char **path)
{
	if (!path)
	{
		printf("Minishell: command not found\n");
		exit(EXIT_FAILURE);
	}
}

int	free_tab(char **tab)
{
	while (tab[g_b.i])
		free(tab[g_b.i++]);
	free (tab);
	return (1);
}

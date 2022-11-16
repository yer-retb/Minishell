/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:31:15 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*expand_in_hd(char *str)
{
	char	*tmp;

	tmp = detect_doller(str, g_b.my_env);
	if (!tmp)
		tmp = ft_strdup("");
	return (tmp);
}

int	herdoc(char *str)
{
	char	*cmd;
	int		fdd[2];

	if (pipe(fdd) == -1)
	{
		printf ("error\n");
		exit(g_b.exit_val);
	}
	cmd = NULL;
	cmd = readline(">");
	while (cmd && ft_strcmp(cmd, str) != 0)
	{
		cmd = expand_in_hd(cmd);
		write(fdd[1], cmd, ft_strlen(cmd));
		write(fdd[1], "\n", 1);
		free(cmd);
		cmd = readline(">");
	}
	free(cmd);
	close (fdd[1]);
	return (fdd[0]);
}

void	excut_herdoc(t_data *data)
{
	t_red	*tmp;
	int		i;

	i = 0;
	while (i < data[0].size)
	{
		if (data[i].red && data[i].red->type == 5)
		{
			tmp = data[i].red;
			while (tmp)
			{
				if (tmp->type == 5)
					data[i].in = herdoc(tmp->file);
				tmp = tmp->next;
			}
		}
		i++;
	}
}

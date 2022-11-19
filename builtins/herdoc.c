/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:26:51 by yer-retb         ###   ########.fr       */
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

	pipe(fdd);
	cmd = NULL;
	cmd = readline(">");
	while (cmd && ft_strcmp(cmd, str) != 0 && g_b.sg_hd != -1)
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

int	excut_herdoc(t_data *data)
{
	t_red	*tmp;
	int		i;

	i = 0;
	while (i < data[0].size)
	{
		if (data[i].red)
		{
			tmp = data[i].red;
			while (tmp)
			{
				if (tmp->type == 5)
				{
					g_b.sg_hd = 2;
					data[i].in = herdoc(tmp->file);
					if (g_b.sg_hd == -1)
						return (0);
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (1);
}

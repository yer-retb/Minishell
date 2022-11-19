/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:28:03 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:32:55 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	ft_cnf(void)
{
	if (g_b.cnf == 127)
		exit(0);
	printf("Minishell: : command not found\n");
	exit(127);
}

void	ft_excut_cmd(t_data data, char **path)
{
	int		i;
	char	*cmd;

	i = -1;
	error(path);
	if (data.str)
	{
		if (scan_path(data.str[0]) == 0)
		{
			if (data.str[0][0] == '\0')
				ft_cnf();
			cmd = ft_strjoin_no_free("/", data.str[0]);
			while (path[++i])
				path[i] = ft_strjoin_no_free(path[i], cmd);
			cmd = check_command(path, data.str[0]);
			if (cmd)
			{
				data.str[0] = cmd;
				execute(data);
			}
		}
		else if (check_path(data.str[0]))
			execute(data);
	}
}

void	bash_builtin(t_data data, char **path, int *prosid)
{
	signal (SIGQUIT, SIG_IGN);
	signal (SIGINT, SIG_IGN);
	g_b.id = fork();
	*prosid = g_b.id;
	if (g_b.id == 0)
	{
		signal (SIGQUIT, SIG_DFL);
		signal (SIGINT, SIG_DFL);
		ft_excut_cmd(data, path);
	}
}

char	**get_binary_file(t_env *env)
{
	t_env	*save;
	t_env	*tmp;
	char	**pathlist;

	save = env;
	tmp = env;
	while (save)
	{
		if (ft_strcmp(save->name, "PATH") == 0)
			pathlist = ft_split(save->path, ':');
		save = save->next;
	}
	return (pathlist);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

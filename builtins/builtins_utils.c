/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:37:42 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:57:32 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	execute(t_data data)
{
	int	i;

	i = 0;
	if (data.in == -1 || data.out == -1)
		exit(1);
	dup2(data.in, 0);
	dup2(data.out, 1);
	if (data.in)
		close(data.in);
	if (data.out > 1)
		close(data.out);
	while (i < 2)
	{
		close(g_b.pipes[i][1]);
		close(g_b.pipes[i][0]);
		i++;
	}
	ft_is_directory(data.str[0]);
	if (execve(data.str[0], data.str, g_b.my_env) == -1)
	{
		perror("execve");
		exit(127);
	}
	exit(g_b.exit_val);
}

int	scan_path(char *cmd)
{
	int	n;

	n = 0;
	while (cmd[n])
	{
		if (cmd[n] == '/')
			return (1);
		n++;
	}
	return (0);
}

char	*check_command(char **files, char *cmd)
{
	int			fd;
	int			i;

	i = 0;
	while (files[i])
	{
		fd = access(files[i], F_OK);
		if (fd != -1)
			return (files[i]);
		i++;
	}
	printf("Minishell: %s: command not found\n", cmd);
	g_b.is = 0;
	g_b.exit_val = 127;
	exit(g_b.exit_val);
	return (NULL);
}

int	check_path(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
	{
		printf("Minishell: %s: No such file or directory\n", str);
		g_b.is = 0;
		g_b.exit_val = 1;
		exit(g_b.exit_val);
	}
	return (1);
}

void	print_fd(int args_num, int fd, ...)
{
	va_list	ap;
	int		i;

	i = -1;
	va_start (ap, fd);
	while (++i < args_num)
		ft_putstr_fd(va_arg(ap, char *), fd);
	va_end(ap);
}

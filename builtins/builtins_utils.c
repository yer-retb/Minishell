#include "../include/include.h"

void	execute(t_data data)
{
	execve(data.str[0], data.str, NULL);
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
	int	fd;
	int	i;

	i = 0;
	while (files[i])
	{
		fd = access(files[i], F_OK);
		if (fd != -1)
			return (files[i]);
		i++;
	}
	printf("Minishell: %s: command not found\n", cmd);
	exit_val = 127;
	return (NULL);
}

int	check_path(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
	{
		printf("Minishell: %s: No such file or directory\n", str);
		exit_val = 1;
		return (0);
	}
	return (1);
}
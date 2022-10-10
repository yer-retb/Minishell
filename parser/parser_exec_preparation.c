/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_preparation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:51:45 by enja              #+#    #+#             */
/*   Updated: 2022/10/10 02:30:04 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include <sys/wait.h>
t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	return (data);
}

void	add_data(t_data **save, t_data *data)
{
	t_data	*head;

	head = *save;
	if (head == NULL)
	{
		*save = data;
		return ;
	}
	while (head->next_data)
	{
		head = head->next_data;
	}
	head->next_data = data;
	data->next_data = NULL;
}

int	check_pipe(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '|')
			return (1);
		i++;
	}
	return (0);
}

char	**assing_atrr(char **tab, t_data *data)
{
	char *path = "/bin/";
	char **command = NULL;
	int	i;

	(void)data;
	tab[0] = ft_strjoin_no_free(path, tab[0]);
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '>' || tab[i][0] == '<')
			break ;
		else
			command = cmd_tab(command, tab[i]);
		i++;
	}
	i = 0;
	// while (command[i])
	// 	printf("%s\n", command[i++]);
	return(command);
}

void	execute(char **cmd, char *intfile)
{
	int fd;
	
	fd = open(intfile, O_CREAT | O_RDWR , 0777);
	
	if (fork() == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(cmd[0], cmd, NULL);
	}
	while (waitpid(-1,NULL,0) == -1);

}
void	parser_exec_preparation(char **tab)
{
	int	i;
	t_data *data;
	char **cmd;

	data = init_data();
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '>')
		{
			cmd = assing_atrr(tab, data);
			execute(cmd, tab[i + 1]);
		}
		i++;
		write(2,"daadsa\n",8);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:50:49 by enja              #+#    #+#             */
/*   Updated: 2022/10/26 12:55:59 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	ft_isalnum2(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
		|| (c == '_'))
		return (1);
	else
		return (0);
}

int	check_string(char **str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if(ft_isdigit(str[i][0]))
				return (1);
			if (!ft_isalnum2(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}

void	built_export(t_env *envirement, char **str)
{
	int		i;
	t_env	*env;
	char	**tmp;

	env = envirement;
	i = 0;
	if (!str[0])
	{
		while (env)
		{
			if (env->name && env->path)
				printf("declare -x %s=\"%s\"\n", env->name, env->path);
			else if(env->name)
				printf("declare -x %s\n", env->name);
			env = env->next;
		}
	}
	else 
	{
		if (check_string(str))
		{
			printf("Minishell: export: not a valid identifier\n");
			return ;
		}
		while (str && str[i])
		{
			tmp = ft_split(str[i], '=');
			list_at_back4(&env, init_env1(tmp));
			i++;
		}
	}
}

void	delet_node(t_env **head, char *name, int pos)
{
	t_env	*save;
	t_env	*tmp;

	save = *head;
	tmp = *head;
	(void)name;
	
	if (!head)
		return ;
	else if (pos == 1)
	{
		*head = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		save = tmp;
		tmp = tmp->next;
		save->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}

}

void	built_unset(t_env *envirement, char **str)
{
	int		i;
	int		j;
	t_env	*env;

	i = 0;
	env = envirement;
	if (!str[0])
		return ;
	else
	{
		if (check_string(str))
		{
			printf("Minishell: unset: not a valid identifier\n");
			return ;
		}
		while (str && str[i])
		{
			env = envirement;
			j = 0;
			while (env && env->next)
			{
				j++;
				if (!ft_strncmp(str[i], env->next->name, ft_strlen(str[i])))
					delet_node(&env, env->name, j);
				env = env->next;
			}
			i++;
		}
	}
}

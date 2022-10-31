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
		|| (c == '_') || (c == '='))
		return (1);
	else
		return (0);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[0]) || str[0] == '=')
			return (1);
		if (!ft_isalnum2(str[i]))
			return (1);
		i++;
	}
	return(0);
}

int	check_duplicate(t_env *envi, char **str)
{
	t_env	*env;
	int		i;

	env = envi;
	i = 0;
	while (env)
	{
		if ((ft_strcmp(env->name, str[0]) == 0) && !str[1])
			return (0);
		else if (ft_strcmp(env->name, str[0]) == 0)
		{
			delet_node(&envi, i);
			return (1);
		}
		env = env->next;
		i++;
	}
	return (1);
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
		while (str && str[i])
		{
			if (str[i][0] == '=')
			{
				printf("Minishell: export: not a valid identifier\n");
				exit_val = 1;
				i++;
				continue ;
			}
			tmp = ft_split(str[i], '=');
			if (check_string(tmp[0]))
			{
				printf("Minishell: export: not a valid identifier\n");
				exit_val = 1;
			}
			if (!tmp[1])
				tmp[1] = ft_strdup("");
			if (check_duplicate(env, tmp) && (!check_string(tmp[0])))
				list_at_back4(&env, init_env1(tmp));
			i++;
		}
	}
}

void	delet_node(t_env **head, int pos)
{
	t_env	*save;
	t_env	*tmp;

	save = *head;
	tmp = *head;
	
	if (!head)
		return ;
	else if (pos == 0)
	{
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		while (pos != 0)
		{
			save = tmp;
			tmp = tmp->next;
			pos--;
		}
		save->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}

}

void	built_unset(t_env **envirement, char **str)
{
	int		i;
	int		j;
	t_env	*env;

	i = 0;
	env = *envirement;
	if (!str[0])
		return ;
	else
	{
		if (check_string(str[0]))
		{
			printf("Minishell: unset: not a valid identifier\n");
			exit_val = 1;
		}
		while (str && str[i])
		{
			env = *envirement;
			j = 0;
			while (env)
			{
				if (!ft_strncmp(str[i], env->name, ft_strlen(str[i])))
				{
					delet_node(envirement, j);
					break ;
				}
				j++;
				env = env->next;
			}
			i++;
		}
	}
}

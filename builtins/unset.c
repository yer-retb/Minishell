/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:53:51 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/07 15:11:57 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

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
			gb.exit_val = 1;
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

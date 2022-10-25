/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:27:54 by enja              #+#    #+#             */
/*   Updated: 2022/10/25 03:45:19 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_env	*init_env1(char **str)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->name = str[0];
	env->path =	str[1];
	env->next = NULL;
	return (env);
}

void	list_at_back4(t_env **save, t_env *node)
{
	t_env	*head;

	head = *save;
	if (head == NULL)
	{
		*save = node;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = node;
	node->next = NULL;
}

t_env	*envirement_list(char **my_env)
{
	t_env	*env;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = NULL;
	while (my_env && my_env[i])
	{
		tmp = ft_split(my_env[i], '=');
		list_at_back4(&env, init_env1(tmp));
		i++;
	}
	return (env);
}

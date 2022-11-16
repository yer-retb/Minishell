/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:57:30 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:57:34 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_env	*init_env1(char **str)
{
	t_env	*env;

	env = ft_malloc(sizeof(t_env));
	env->name = str[0];
	env->path = str[1];
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
	if (!my_env)
	{
		env->name = ft_strdup("");
		env->path = ft_strdup("");
		env->next = NULL;
		return (env);
	}
	while (my_env && my_env[i])
	{
		tmp = ft_split(my_env[i], '=');
		list_at_back4(&env, init_env1(tmp));
		i++;
	}
	return (env);
}

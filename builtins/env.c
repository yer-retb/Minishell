/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:57 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/03 18:52:11 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	built_env(t_env *envirement)
{
	t_env	*env;

	env = envirement;
	while (env)
	{
		if (env->name && env->path)
			printf("%s=%s\n", env->name, env->path);
		env = env->next;
	}
}

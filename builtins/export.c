/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:57:46 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:57:48 by yer-retb         ###   ########.fr       */
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
	while ((ft_strlen(str) != 0) && str[i])
	{
		if (ft_isdigit(str[0]) || str[0] == '=')
			return (1);
		if (!ft_isalnum2(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_equel(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	export_utils(t_env *envirement, char **str)
{
	char	**tmp;
	t_env	*env;
	int		i;

	env = envirement;
	i = 0;
	while (str && (ft_strlen(str[i]) != 0) && str[i])
	{
		if (str[i][0] == '=')
		{
			export_print_error("export");
			i++;
			continue ;
		}
		tmp = ft_split(str[i], '=');
		if (check_string(tmp[0]))
			export_print_error("export");
		if (!tmp[1] && check_equel(str[i]))
			tmp[1] = ft_strdup("");
		if (check_duplicate(env, tmp) && (!check_string(tmp[0])))
			list_at_back4(&env, init_env1(tmp));
		i++;
	}
	i = 0;
}

void	built_export(t_env *envirement, char **str, int fd)
{
	t_env	*env;

	env = envirement;
	if (!str[0])
	{
		while (env)
		{
			if (env->name && env->path)
				print_fd(6, fd, "declare -x ", env->name,
					"=\"", env->path, "\"", "\n");
			else if (env->name)
				print_fd(3, fd, "declare -x ", env->name, "\n");
			env = env->next;
		}
	}
	else
		export_utils(env, str);
}

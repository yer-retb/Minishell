/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:50:49 by enja              #+#    #+#             */
/*   Updated: 2022/11/10 22:46:54 by yer-retb         ###   ########.fr       */
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
	while (str[i])
	{
		if (ft_isdigit(str[0]) || str[0] == '=')
			return (1);
		if (!ft_isalnum2(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	export_print_error(char *str)
{
	print_fd(3, STDERR_FILENO, "Minishell: ", str,
		": not a valid identifier\n");
	g_b.exit_val = 1;
}

void	export_utils(t_env *envirement, char **str)
{
	char	**tmp;
	t_env	*env;
	int		i;

	env = envirement;
	i = 0;
	while (str && str[i])
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
		if (!tmp[1] && str[i][ft_strlen(str[i]) - 1] == '=')
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

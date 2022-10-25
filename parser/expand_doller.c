/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_doller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:04:23 by enja              #+#    #+#             */
/*   Updated: 2022/10/25 09:36:34 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*rejoin_tab(char **tab)
{
	int		i;
	char	*pt;

	i = 0;
	pt = NULL;
	while (tab && tab[i])
	{
		if (tab[i][0] != '\0')
			pt = ft_strjoin(pt, tab[i]);
		i++;
	}
	i = 0;
	free(tab);
	return (pt);
}

char	*join_env(char **tab, char *ptr)
{
	int		i;
	char	*pt;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '$' && ptr)
		{
			free(tab[i]);
			tab[i] = ptr;
			break ;
		}
		else if (tab[i][0] == '$' && ptr == NULL)
		{
			free(tab[i]);
			tab[i] = "";
			break ;
		}
		i++;
	}
	pt = rejoin_tab(tab);
	return (pt);
}

char	*merge_str(char *str, char *ptr)
{
	char	*st;
	char	**tabst;
	int		i;

	i = 0;
	tabst = NULL;
	st = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			st = get_char(st, str[i++]);
			while (str[i] && ft_isalnum(str[i]))
				st = get_char(st, str[i++]);
		}
		else
		{
			while (str[i] && str[i] != '$')
				st = get_char(st, str[i++]);
		}
		tabst = cmd_tab(tabst, st);
		st = NULL;
	}
	free(str);
	return (join_env(tabst, ptr));
}

char	*get_env(char *ptr, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(ptr, env[i], ft_strlen(ptr)) == 0)
		{
			ptr = ft_strjoin_no_free(ptr, "=");
			if (!ft_strncmp(ptr, env[i], ft_strlen(ptr)))
				ptr = moded_strnstr(env[i], ptr, ft_strlen(env[i]));
			// printf("---> %s\n", ptr);
			return (ptr);
		}
		i++;
	}
	free(ptr);
	return (NULL);
}

char	*norm_doller(int *x, char *str, char *ptr, char **env)
{
	int	i;

	i = *x;
	i++;
	while (str[i] && ft_isalnum(str[i]))
		ptr = get_char(ptr, str[i++]);
	ptr = get_env(ptr, env);
	str = merge_str(str, ptr);
	ptr = NULL;
	i = 0;
	*x = i;
	return (str);
}

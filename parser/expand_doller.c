/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_doller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:04:23 by enja              #+#    #+#             */
/*   Updated: 2022/10/05 13:14:14 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*rejoin_tab(char **tab)
{
	int		i;
	char	*pt;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] != '\0')
			pt = ft_strjoin_no_free(pt, tab[i]);
		i++;
	}
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
			tab[i] = ptr;
			break ;
		}
		else if (tab[i][0] == '$' && ptr == NULL)
		{
			tab[i] = ft_strdup("");
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
			tabst = cmd_tab(tabst, st);
		}
		else
		{
			while (str[i] && str[i] != '$')
				st = get_char(st, str[i++]);
			tabst = cmd_tab(tabst, st);
		}
		st = NULL;
	}
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
			ptr = ft_strnstr(env[i], ptr, ft_strlen(env[i]));
			return (ptr);
		}
		i++;
	}
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
	if (!str)
		return (ft_strdup(""));
	i = 0;
	if (ptr != NULL)
		ptr = NULL;
	*x = i;
	return (str);
}

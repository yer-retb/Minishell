/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_doller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:04:23 by enja              #+#    #+#             */
/*   Updated: 2022/10/07 18:40:26 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*moded_strnstr(char *str, char *needle, int len)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (needle[i] == '\0')
		return ((char *)str);
	while ((str[i]) && (i < len))
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				s = ft_strdup((char *)&str[i + j]);
				free(needle);
				return (s);
			}
		}
		i++;
	}
	free(needle);
	return (0);
}

char	*rejoin_tab(char **tab)
{
	int		i;
	char	*pt;

	i = 0;
	pt = NULL;
	while (tab[i])
	{
		if (tab[i][0] != '\0')
			pt = ft_strjoin_no_free(pt, tab[i]);
		i++;
	}
	i = 0;
	// printf("%p\n", tab);d;
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
			tab[i] = 0;
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
			// printf("%p\n", ptr);
			ptr = moded_strnstr(env[i], ptr, ft_strlen(env[i]));
			// printf("%p\n", ptr);
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
	printf("%p\n", ptr);
	// printf("%p\n", str);
	str = merge_str(str, ptr);
	free(ptr);
	ptr = NULL;
	i = 0;
	*x = i;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_tab2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:55:46 by enja              #+#    #+#             */
/*   Updated: 2022/10/07 19:56:54 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*get_tab_handler_2(char *newcmd, char *value, int *i, char t)
{
	int	a;

	a = *i;
	while (value[a] && value[a] != t)
		newcmd = get_char(newcmd, value[a++]);
	*i = a;
	return (newcmd);
}

char	*get_tab_handler(char *newcmd, char *value, int *i)
{
	int	a;

	a = *i;
	if (value[a] == '\"')
	{
		a++;
		newcmd = get_tab_handler_2(newcmd, value, &a, '\"');
	}
	else if (value[a] == '\'')
	{
		a++;
		newcmd = get_tab_handler_2(newcmd, value, &a, '\'');
	}
	else
	{
		while (value[a] && value[a] != '\"' && value[a] != '\'')
			newcmd = get_char(newcmd, value[a++]);
	}
	*i = a;
	return (newcmd);
}

char	**get_tab_handler_3(char **cmd_table, char **newcmd, int *i)
{
	cmd_table = cmd_tab(cmd_table, *newcmd);
	printf("hada %p\n", newcmd);
	*newcmd = NULL;
	*i = 0;
	return (cmd_table);
}

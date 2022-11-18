/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/17 05:17:17 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	tdm(char **arr)
{
	int	a;

	if (arr[0] == NULL)
		return (0);
	a = 0;
	while (arr[a] != NULL)
		a++;
	return (a);
}

char	*get_char(char *str, char c)
{
	char	*strnw;
	int		i;

	i = 0;
	if (!str)
	{
		str = ft_malloc (sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	strnw = ft_malloc((ft_strlen(str) + 2) * sizeof(char));
	while (str[i])
	{
		strnw[i] = str[i];
		i++;
	}
	strnw[i++] = c;
	strnw[i] = '\0';
	free(str);
	return (strnw);
}

char	**cmd_tab(char **cmd_table, char *newcmd)
{
	int		i;
	char	**newtable;

	i = 0;
	if (!cmd_table)
	{
		cmd_table = ft_malloc(2 * sizeof(char *));
		cmd_table[0] = newcmd;
		cmd_table[1] = NULL;
		return (cmd_table);
	}
	newtable = ft_malloc((tdm(cmd_table) + 2) * sizeof(char *));
	while (cmd_table[i])
	{
		newtable[i] = cmd_table[i];
		i++;
	}
	newtable[i++] = newcmd;
	newtable[i] = NULL;
	free(cmd_table);
	return (newtable);
}

char	**init_tab_parser(t_parser *st_list)
{
	int			i;
	char		*newcmd;
	char		**cmd_table;
	t_parser	*head;

	cmd_table = NULL;
	newcmd = NULL;
	head = st_list;
	i = 0;
	return (parser_get_tab(head, cmd_table, newcmd, i));
}

char	**parser_get_tab(t_parser *head, char **cmd_table, char *newcmd, int i)
{
	while (head && head->token_struct->value)
	{
		if (head->token_struct->value[i] == '\"' || \
			head->token_struct->value[i] == '\'')
		{
			newcmd = get_tab_handler(newcmd, head->token_struct->value, &i);
			i++;
			if (head->token_struct->value[i] == '\0')
			{
				cmd_table = get_tab_handler_3(cmd_table, &newcmd, &i);
				head = head->next_token;
			}
		}
		else
		{
			newcmd = get_tab_handler(newcmd, head->token_struct->value, &i);
			if (head->token_struct->value[i] == '\0')
			{
				cmd_table = get_tab_handler_3(cmd_table, &newcmd, &i);
				head = head->next_token;
			}
		}
	}
	return (cmd_table);
}

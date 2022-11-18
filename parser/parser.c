/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:47 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/17 08:45:47 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	*doller_quats(char *str, char *ptr, char **env, int *i)
{
	if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
		(*i)++;
	}
	else if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\"')
		{
			if (str[*i] && str[*i] == '$' && ft_isalpha(str[*i + 1]))
			{
				str = norm_doller(i, str, ptr, env);
				return (str);
			}
			(*i)++;
		}
		if (str[*i])
			(*i)++;
	}
	return (str);
}

char	*detect_doller(char *str, char **env)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (str && str[i])
	{
		if (str[i] && str[i] == '\'')
			str = doller_quats(str, ptr, env, &i);
		else if (str[i] && str[i] == '$' && (ft_isalpha(str[i + 1])))
			str = norm_doller(&i, str, ptr, env);
		else if (str[i] && str[i] == '$' && ft_isdigit(str[i + 1]))
			str = ft_strdup(str + 2);
		else if (str[i] && str[i] == '$' && str[i + 1] == '?')
			str = ft_itoa(g_b.exit_val);
		else if (str[i] && str[i] == '\"')
			str = doller_quats(str, ptr, env, &i);
		else if (str && str[i])
			i++;
	}
	return (str);
}

void	expand_dollar(t_parser *head, char **env)
{
	int		tmp;

	while (head)
	{
		if (tmp != TOKEN_HRDOC)
		{
			head->token_struct->value
				= detect_doller(head->token_struct->value, env);
		}
		tmp = head->token_struct->e_type;
		head = head->next_token;
	}
}

void	*parser_check_syntax(t_parser *head)
{
	if (head->token_struct->e_type == TOKEN_PIPE)
		return (msg_syntax_error(head->token_struct->value));
	while (head)
	{
		if (head->token_struct->e_type == TOKEN_STR)
		{
			if (head->next_token)
				head = head->next_token;
			else
				return ("TRUE");
		}
		if (head->token_struct->e_type != TOKEN_STR)
		{
			if (head->next_token && head->token_struct->e_type == TOKEN_PIPE
				&& head->next_token->token_struct->e_type != TOKEN_PIPE)
				head = head->next_token;
			else if (head->next_token
				&& head->next_token->token_struct->e_type == TOKEN_STR)
				head = head->next_token;
			else
				return (msg_syntax_error(head->token_struct->value));
		}
	}
	return ("TRUE");
}

void	*parser_get(t_parser *st_list, char **env)
{
	char	**tab;
	int		i;

	i = -1;
	if (!st_list)
		return (NULL);
	if (!parser_check_syntax(st_list))
		return (NULL);
	expand_dollar(st_list, env);
	tab = init_tab_parser(st_list);
	return (tab);
}

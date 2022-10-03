/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:04:15 by enja              #+#    #+#             */
/*   Updated: 2022/09/30 23:50:30 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	parser_check_syntax(t_parser *head)
{
	while (head)
	{
		if (head->token_struct->e_type == TOKEN_STR)
		{
			if (head->next_token)
				head = head->next_token;
			else
				return ;
		}
		if (head->token_struct->e_type != TOKEN_STR)
		{
			if (head->next_token && head->token_struct->e_type == TOKEN_PIPE
				&& head->next_token->token_struct->e_type != TOKEN_PIPE)
				head = head->next_token;
			else if (head->next_token && \
			head->next_token->token_struct->e_type == TOKEN_STR)
				head = head->next_token;
			else
				msg_syntax_error(head->token_struct->value);
		}
	}
}

char	*merge_str(char *str, char *ptr)
{

}

char	*get_env(char *ptr, char **env)
{
	int i = 0;

	while(env[i] != NULL)
	{
		if (ft_strncmp(ptr, env[i], ft_strlen(ptr)) == 0)
		{
			ptr = ft_strjoin_no_free(ptr, "=");
			ptr = ft_strnstr(env[i], ptr, ft_strlen(env[i]));
			return (ptr);
		}
		i++;
	}
	return ("NULL");
}

char	*detect_doller(char *str, char **env)
{
	int		i = 0;
	char	*ptr = NULL;

	while (str[i])
	{
		if (str[i] && str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
		}
		else if (str[i] == '$' && ft_isalpha(str[i + 1]))
		{
			i++;
			while (str[i] && ft_isalnum(str[i]))
				ptr = get_char(ptr, str[i++]);
			ptr = get_env(ptr, env);
			str = merge_str(str, ptr);
			printf("expanded : %s\n", ptr);
			ptr = NULL;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
			{
				if (str[i] == '$' && ft_isalpha(str[i + 1]))
				{
					i++;
					while (str[i] && ft_isalnum(str[i]))
						ptr = get_char(ptr, str[i++]);
					ptr = get_env(ptr, env);
					str = merge_str(str, ptr);
					ptr = NULL;
				}
				i++;
			}
		}
		if (str[i] != '\0' && str[i] != '$')
			i++;
		
	}
	return (str);
}

void	expand_dollar(t_parser *head, char **env)
{
	while (head)
		{
			head->token_struct->value = detect_doller(head->token_struct->value, env);
			head = head->next_token;
		}
}

void	parser_get(t_parser *st_list, char **env)
{
	char	**tab;
	int		i = -1;
	
	if (!st_list)
		return ;
	(void)tab;
	(void)env;
	if (st_list->token_struct->e_type == TOKEN_PIPE)
		msg_syntax_error(st_list->token_struct->value);
	parser_check_syntax(st_list);
	expand_dollar(st_list, env);
	tab = parser_get_tab(st_list);
	while(tab[++i])
		printf("%s\n", tab[i]);
}

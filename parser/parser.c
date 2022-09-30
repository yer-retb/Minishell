/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:04:15 by enja              #+#    #+#             */
/*   Updated: 2022/09/20 06:14:24 by enja             ###   ########.fr       */
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

char	*ft_switch(char *str, char **env)
{
	int		i;
	char	*s1;

	s1 = str;
	i = ft_strlen(s1);
	s1 = ft_strjoin_no_free(s1, "=");
	while (env[i] != '\0')
	{
		if (!(ft_strncmp(s1, env[i], ft_strlen(s1))))
		{
			printf("hi\n");
			s1 = ft_strnstr(env[i], s1, ft_strlen(env[i]));
			return (s1);
		}
		i++;
	}
	printf("### %s\n", str);
	return (str);
}

char	*detect_doller(char *str, char **env)
{
	int i;
	char *s1;

	i = 0;
	s1 = malloc(sizeof (char) * ft_strlen(str));
	if (!s1)
		return (NULL);
	if (str[0] == '$' && ft_isalpha(str[1]))
	{
		while (str[i] && ft_isalnum(str[i + 1]))
		{
			s1[i] = str[i + 1];
			i++;
		}
		s1[i] = '\0';
		return (ft_switch(s1, env));
	}
	return (str);
}

void	expand_dollar(t_parser *head, char **env)
{
	while (head)
		{
			head->token_struct->value = detect_doller(head->token_struct->value, env);
			// printf("->> %s\n", head->token_struct->value);
			head = head->next_token;
		}
}

void	parser_get(t_parser *st_list, char **env)
{
	if (!st_list)
		return ;
	if (st_list->token_struct->e_type == TOKEN_PIPE)
		msg_syntax_error(st_list->token_struct->value);
	parser_check_syntax(st_list);
	expand_dollar(st_list, env);
	/** your part **/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:39:39 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/18 00:27:24 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_token	*the_separater(t_lexer *lexer)
{
	if (lexer->c == '|')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_PIPE, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '>' && lexer->content[lexer->i + 1] == '>')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_GG, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '<' && lexer->content[lexer->i + 1] == '<')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_LL, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '>' && lexer->content[lexer->i - 1] != '>' )
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_OUTPUT, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '<' && lexer->content[lexer->i - 1] != '<')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_INPUT, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '\'')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_SINGLE_Q, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '"')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_DOUBLE_Q, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '$')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_DOLER, lexer_get_c_as_str(lexer))));
	return (NULL);
}

t_token	*lexer_get_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (lexer->c == ' ' || lexer->c == '\t')
			lexer_skip_space (lexer);
		if (lexer->c == '\"')
			return (collect_string(lexer, '\"'));
		if (lexer->c == '\'')
			return (collect_string(lexer, '\''));
		if (lexer->c == '-')
			return (collect_flag(lexer));
		if (lexer->c != '\0' && ft_isascii(lexer->c)
			&& (!(is_rederection(lexer->c)))
			&& (!(lexer->c == ' ' && lexer->c == '\t')))
			return (collect_cmd(lexer));
		if (lexer->c == '>' && lexer->content[lexer->i + 1] == '>')
			return (collect_cmd(lexer));
		if (lexer->c == '<' && lexer->content[lexer->i + 1] == '<')
			return (collect_cmd(lexer));
		if (is_rederection(lexer->c))
			return (the_separater(lexer));
	}
	return (NULL);
}

t_token	*collect_string(t_lexer *lexer, char t)
{
	char	*value;
	char	*str;

	lexer_advence(lexer);
	value = malloc(sizeof(char));
	while (lexer->c != '\'' && t == '\'')
	{
		if (lexer->c == '\0')
		{
			printf("error\n");
			break ;
		}
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	while (lexer->c != '\"' && t == '\"')
	{
		if (lexer->c == '\0')
		{
			printf("error\n");
			break ;
		}
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	lexer_advence(lexer);
	return (init_token(TOKEN_STR, value));
}

t_token	*appends_end_heredoc(t_lexer *lexer, char *str, char *value)
{
	int		i;

	i = 0;
	while (lexer->c == '>' || lexer->c == '<')
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
		i++;
		if (i > 2)
		{
			printf("error\n");
			exit(1);
		}
	}
	if (i == 2 && lexer->content[lexer->i -1] == '>')
		return (init_token(TOKEN_GG, value));
	if (i == 2 && lexer->content[lexer->i -1] == '<')
		return (init_token(TOKEN_LL, value));
	return (NULL);
}

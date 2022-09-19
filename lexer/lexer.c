/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:39:39 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 03:03:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_token	*the_separater(t_lexer *lexer)
{
	if (lexer->c == '|')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_PIPE, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '>')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_OUT, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '<')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_IN, lexer_get_c_as_str(lexer))));
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
			return (appends_end_heredoc(lexer));
		if (lexer->c == '<' && lexer->content[lexer->i + 1] == '<')
			return (appends_end_heredoc(lexer));
		if (is_rederection(lexer->c))
			return (the_separater(lexer));
	}
	return (NULL);
}

t_token	*collect_string(t_lexer *lexer, char t)
{
	char	*value;
	char	*str;

	value = NULL;
	lexer_advence(lexer);
	while (lexer->c != '\'' && t == '\'')
	{
		if (lexer->c == '\0')
			msg_error();
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	while (lexer->c != '\"' && t == '\"')
	{
		if (lexer->c == '\0')
			msg_error();
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	lexer_advence(lexer);
	return (init_token(TOKEN_STR, value));
}

t_token	*appends_end_heredoc(t_lexer *lexer)
{
	int		i;
	char	*value;
	char	*str;

	value = NULL;
	i = 0;
	while (i < 2)
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
		i++;
	}
	if (lexer->content[lexer->i - 1] == '>')
		return (init_token(TOKEN_APPEND, value));
	if (lexer->content[lexer->i -1] == '<')
		return (init_token(TOKEN_HRDOC, value));
	return (NULL);
}

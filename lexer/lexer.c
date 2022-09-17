/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:39:39 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 01:35:14 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_lexer	*init_lexer(char *content)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->content = content;
	lexer->i = 0;
	lexer->c = content[lexer->i];
	return (lexer);
}

void	lexer_advence(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}

void	lexer_skip_space(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lexer_advence(lexer);
}

t_token	*the_separater(t_lexer *lexer)
{
	if (lexer->c == '|')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_PIPE, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '>')
		return (lexer_advence_with_token(lexer,
				init_token(TOKEN_OUTPUT, lexer_get_c_as_str(lexer))));
	else if (lexer->c == '<')
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
		if (lexer->c == '"')
			return (collect_string(lexer));
		if (lexer->c == '-')
			return (collect_flag(lexer));
		if (ft_isalnum(lexer->c))
			return (collect_cmd(lexer));
		if (is_rederection(lexer->c))
			return (the_separater(lexer));
	}
	return (NULL);
}

t_token	*lexer_advence_with_token(t_lexer *lexer, t_token *token)
{
	lexer_advence(lexer);
	return (token);
}

t_token	*collect_string(t_lexer *lexer)
{
	char	*value;
	char	*str;

	lexer_advence(lexer);
	value = malloc(sizeof(char));
	while (lexer->c != '"')
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	lexer_advence(lexer);
	return (init_token(TOKEN_STR, value));
}

t_token	*collect_flag(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = malloc(sizeof(char));
	str = lexer_get_c_as_str(lexer);
	value = ft_strjoin(value, str);
	lexer_advence(lexer);
	while (lexer->c != ' ' && lexer->c != '\t' && (!(is_rederection(lexer->c))))
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	return (init_token(TOKEN_FLAG, value));
}

t_token	*collect_cmd(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = malloc(sizeof(char));
	while (lexer->c != ' ' && lexer->c != '\t' && (!(is_rederection(lexer->c))))
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	return (init_token(TOKEN_CMD, value));
}

char	*lexer_get_c_as_str(t_lexer *lexer)
{
	char	*str;

	str = malloc (sizeof(char) * 2);
	str[0] = lexer->c;
	str[1] = '\0';
	return (str);
}

int	is_rederection(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '\'' || c == '\"' || c == '$')
		return (1);
	return (0);
}
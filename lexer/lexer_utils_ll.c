/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:16:35 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 09:13:58 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	is_rederection(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '\'' || c == '\"' || c == '$')
		return (1);
	return (0);
}

t_token	*collect_flag(t_lexer *lexer)
{
	char	*value = NULL;
	char	*str;

	str = lexer_get_c_as_str(lexer);
	value = ft_strjoin(value, str);
	lexer_advence(lexer);
	while (lexer->c != ' ' && lexer->c != '\t' && lexer->c != '\0'
		&& (!(is_rederection(lexer->c))))
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	return (init_token(TOKEN_FLAG, value));
}

t_token	*collect_cmd(t_lexer *lexer)
{
	char	*value = NULL;
	char	*str;

	while (lexer->c != '\0' && (!(is_rederection(lexer->c)))
		&& lexer->c != ' ' && lexer->c != '\t')
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	return (init_token(TOKEN_STR, value));
}

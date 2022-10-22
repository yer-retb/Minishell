/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:16:35 by enja              #+#    #+#             */
/*   Updated: 2022/10/22 00:43:02 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	is_rederection(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

t_token	*collect_cmd(t_lexer *lexer)
{
	char	*value;
	char	*ptr;
	char	*str;

	value = NULL;
	while (lexer->c != '\0' && (!(is_rederection(lexer->c)))
		&& lexer->c != ' ' && lexer->c != '\t')
	{
		if (lexer->c == '\'' || lexer->c == '\"')
		{
			ptr = collect_string(lexer, lexer->c);
			if (!ptr)
				return (msg_error(EROR, NULL, value));
			value = ft_strjoin(value, ptr);
		}
		else
		{
			str = lexer_get_c_as_str(lexer);
			value = ft_strjoin(value, str);
			lexer_advence(lexer);
		}
	}
	return (init_token(TOKEN_STR, value));
}

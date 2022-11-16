/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:59:19 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:59:21 by yer-retb         ###   ########.fr       */
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

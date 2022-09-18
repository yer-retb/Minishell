#include "../include/include.h"

int	is_rederection(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '\'' || c == '\"' || c == '$')
		return (1);
	return (0);
}

t_token	*collect_flag(t_lexer *lexer)
{
	char	*value;
	char	*str;

	value = malloc(sizeof(char));
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
	char	*value;
	char	*str;

	str = NULL;
	value = malloc(sizeof(char));
	appends_end_heredoc(lexer, str, value);
	while (lexer->c != '\0' && (!(is_rederection(lexer->c)))
		&& lexer->c != ' ' && lexer->c != '\t')
	{
		str = lexer_get_c_as_str(lexer);
		value = ft_strjoin(value, str);
		lexer_advence(lexer);
	}
	return (init_token(TOKEN_CMD, value));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:35:07 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 09:51:50 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct n_lexer
{
	char	c;
	int		i;
	char	*content;

}	t_lexer;

t_lexer	*init_lexer(char *content);

void	lexer_advence(t_lexer *lexer);

void	lexer_skip_space(t_lexer *lexer);

t_token	*lexer_get_next_token(t_lexer *lexer);

t_token	*collect_string(t_lexer *lexer, char t);

t_token	*collect_cmd(t_lexer *lexer);

t_token	*collect_flag(t_lexer *lexer);

t_token	*the_separater(t_lexer *lexer);

t_token	*appends_end_heredoc(t_lexer *lexer);

t_token	*lexer_advence_with_token(t_lexer *lexer, t_token *token);

char	*lexer_get_c_as_str(t_lexer *lexer);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:58:33 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:58:35 by yer-retb         ###   ########.fr       */
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

char	*collect_string(t_lexer *lexer, char t);

t_token	*collect_cmd(t_lexer *lexer);

t_token	*the_separater(t_lexer *lexer);

t_token	*appends_end_heredoc(t_lexer *lexer);

t_token	*lexer_advence_with_token(t_lexer *lexer, t_token *token);

char	*lexer_get_c_as_str(t_lexer *lexer);

#endif

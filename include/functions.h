/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:45:10 by enja              #+#    #+#             */
/*   Updated: 2022/10/22 00:42:44 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define TRUE			1
# define TOKEN_STR 		0
# define TOKEN_PIPE		1
# define TOKEN_IN		2
# define TOKEN_OUT		3
# define TOKEN_HRDOC	4
# define TOKEN_APPEND	5
# define TOKEN_FLAG		6
# define EROR			7

char		*get_prompt(void);
void		clear_prompt(void);
int			is_rederection(char c);
t_token		*msg_error(int e_type, char *val, char *value);
void		*msg_error1(void);
void		*msg_cmd_error(char *msg);
void		*msg_syntax_error(char *msg);
char		**init_env(char **env, char **my_env);
t_parser	*start_lexing(char *cmd, t_token *tk, t_parser *hd);
void		init_shell(char **env);

#endif
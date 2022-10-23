/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:48:47 by yer-retb          #+#    #+#             */
/*   Updated: 2022/10/22 08:25:15 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

//*********SYSTEM*********//
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

//*********USEER*********//
# include "token.h"
# include "lexer.h"
# include "../libft/libft.h"
# include "parser_exec.h"
# include "init_nodes.h"
# include "parser.h"
# include "functions.h"
# include "data.h"

typedef struct n_test
{
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;

}	t_test;

#endif

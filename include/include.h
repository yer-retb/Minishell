/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:48:47 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 09:54:45 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H


//*********SYSTEM*********//
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

//*********USEER*********//
# include "token.h"
# include "lexer.h"
# include "../libft/libft.h"
# include "functions.h"
# include "init_nodes.h"
# include "parser.h"

typedef struct n_test
{
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;

} t_test;

#endif

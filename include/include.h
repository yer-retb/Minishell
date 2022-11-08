/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:48:47 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/07 15:12:03 by yer-retb         ###   ########.fr       */
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
# include <string.h>

//*********USEER*********//
# include "token.h"
# include "lexer.h"
# include "../libft/libft.h"
# include "parser_exec.h"
# include "init_nodes.h"
# include "parser.h"
# include "data.h"
# include "builtins.h"
# include "functions.h"

typedef struct n_gb
{
	int ft1;
	int ft2;
	int **pipes;
	int	exit_val;
}t_gb;

t_gb	gb;

typedef struct n_test
{
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;

}	t_test;

#endif

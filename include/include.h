/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:48:47 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:43:02 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

//*********SYSTEM*********//
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/stat.h>

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
	int		ft1;
	int		ft2;
	int		**pipes;
	int		exit_val;
	char	**my_env;
	void	*save[1000000];
	int		index;
	int		i;
	char	*cmd;
	t_psr	*nhead;
	int		cnf;
	int		id;
	int		s_size;
	int		sg_hd;
	int		is;
	int		saved;
}t_gb;

t_gb	g_b;

typedef struct n_test
{
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;

}	t_test;

int		free_tab(char **tab);
void	error(char **path);
void	print_fd(int args_num, int fd, ...);
void	*ft_malloc(int size);
void	ft_signal(void);
void	sig_handler(int sig);

#endif

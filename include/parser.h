/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:08:33 by enja              #+#    #+#             */
/*   Updated: 2022/10/25 13:20:54 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// typedef struct n_red
// {
// 	enum
// 	{
// 		CMD,
// 		ARG,
// 		HRDOC,
// 	} e_red_typ;
// 	char	*file;
// }	t_red;

// typedef struct n_list
// {
// 	char	*command;
// 	char	c;
// 	int		i;
// 	t_red	*red;
// }	t_list;

void	*parser_get(t_parser *st_list, char **env);

void	parser_check_command(t_token *st_list);

void	parser_scan_cmd(t_token *st_list);

void	parser_check_first_token(t_parser *st_list);

char	**parser_get_tab(t_parser *head, char **cmd_table, char *newcmd, int i);

char	**cmd_tab(char **cmd_table, char *newcmd);

char	*get_char(char *str, char c);

int		tdm(char **arr);

// int		check1(char c, int sig);

// int		check(char c);

char	*merge_str(char *str, char *ptr);

char	*get_tab_handler_2(char *newcmd, char *value, int *i, char t);

char	*get_tab_handler(char *newcmd, char *value, int *i);

char	**get_tab_handler_3(char **cmd_table, char **newcmd, int *i);

char	**init_tab_parser(t_parser *st_list);

char	*rejoin_tab(char **tab);

char	*join_env(char **tab, char *ptr);

char	*get_env(char *ptr, char **env);

char	*norm_doller(int *x, char *str, char *ptr, char **env);

/*---------------list & red functions---------------*/

// t_list	*init_list(char *cmd);

// t_red	*my_cmd(int typ, char *file);

// void	list_advence(t_list *list);

// void	list_skip_space(t_list *list);

// t_red	*get_next_list(t_list *list);

// t_red	*list_collect(t_list *list, char d);

// t_red	*list_cmd_collect(t_list *list);

// int		remove_quats(t_list *list, char *d);

// char	*list_get_c_as_str(t_list *list);

#endif

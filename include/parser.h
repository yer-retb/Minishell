/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:58:52 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:58:54 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	*parser_get(t_parser *st_list, char **env);

void	parser_check_command(t_token *st_list);

void	parser_scan_cmd(t_token *st_list);

void	parser_check_first_token(t_parser *st_list);

char	**parser_get_tab(t_parser *head, char **cmd_table, char *newcmd, int i);

char	**cmd_tab(char **cmd_table, char *newcmd);

char	*get_char(char *str, char c);

int		tdm(char **arr);

char	*merge_str(char *str, char *ptr);

char	*get_tab_handler_2(char *newcmd, char *value, int *i, char t);

char	*get_tab_handler(char *newcmd, char *value, int *i);

char	**get_tab_handler_3(char **cmd_table, char **newcmd, int *i);

char	**init_tab_parser(t_parser *st_list);

char	*rejoin_tab(char **tab);

char	*join_env(char **tab, char *ptr);

char	*get_env(char *ptr, char **env);

char	*norm_doller(int *x, char *str, char *ptr, char **env);

char	*detect_doller(char *str, char **env);

#endif

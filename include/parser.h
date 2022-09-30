/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 05:08:33 by enja              #+#    #+#             */
/*   Updated: 2022/09/20 00:15:56 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct n_red
{
	enum
	{
		CMD,
		ARG,
		HRDOC,
	} e_red_typ;

	char	*file;
}	t_red;

typedef struct n_list
{
	char	*command;
	char	c;
	int		i;
	t_red	*red;
}	t_list;

void	parser_get(t_parser *st_list, char **env);

void	parser_check_command(t_token *st_list);

void	parser_scan_cmd(t_token *st_list);

void	parser_check_first_token(t_parser *st_list);

/*---------------list & red functions---------------*/

t_list	*init_list(char *cmd);

t_red	*my_cmd(int typ, char *file);

void	list_advence(t_list *list);

void	list_skip_space(t_list *list);

t_red	*get_next_list(t_list *list);

t_red	*list_collect(t_list *list, char d);

t_red	*list_cmd_collect(t_list *list);

int		remove_quats(t_list *list, char *d);

char	*list_get_c_as_str(t_list *list);

#endif

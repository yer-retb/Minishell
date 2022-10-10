/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:32:19 by enja              #+#    #+#             */
/*   Updated: 2022/10/10 00:22:51 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_EXEC_H
# define PARSER_EXEC_H

typedef struct t_data
{
	int				in;
	int				out;
	char			*path;
	char			*args;
	struct t_data	*next_data;
}	t_data;

t_data	*init_data(void);
void	parser_exec_preparation(char **tab);
int		check_pipe1(char *tab);
void	add_data(t_data **save, t_data *data);
#endif
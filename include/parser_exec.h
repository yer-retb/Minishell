/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:58:42 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:58:44 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_EXEC_H
# define PARSER_EXEC_H

typedef struct n_tkn
{
	enum
	{
		CMD,
		ARG,
		PIPE,
		INF,
		OUTF,
		HRD,
		APD,
	} e_type;
	char	*val;
}	t_tkn;

typedef struct n_psr
{
	t_tkn			*tkn_st;
	struct n_psr	*nx_tkn;
}	t_psr;

typedef struct n_big_node
{
	t_psr				*psr;
	struct n_big_node	*psr_next;
}t_bige_node;

int			check(char *str);
void		*parser_exec_preparation(char **tab, t_psr *hd);
void		add_list_at_back3(t_bige_node **save, t_bige_node *node);
t_tkn		*asing_tk(t_tkn *tkn, char *val, int type);
t_bige_node	*parser_tokenazer(char **tab, t_psr *hd, t_tkn *tk, t_bige_node *b);
t_bige_node	*asing_tk2(t_psr *hd, t_bige_node *bignode);

#endif

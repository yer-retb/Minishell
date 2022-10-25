/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:32:19 by enja              #+#    #+#             */
/*   Updated: 2022/10/25 09:14:25 by enja             ###   ########.fr       */
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

void	*parser_exec_preparation(char **tab, t_psr *hd);

#endif

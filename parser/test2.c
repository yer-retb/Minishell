/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:19:49 by enja              #+#    #+#             */
/*   Updated: 2022/10/22 15:19:50 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	node_size(t_bige_node *bignode)
{
	int			i;
	t_bige_node	*save;

	save = bignode;
	i = 0;
	while (save)
	{
		i++;
		save = save->psr_next;
	}
	return (i);
}
void    check_fdfdfile(char *str)
{
    int fd;
    fd = access(str, F_OK);
    if (fd == -1)
        printf("Minishell: %s: no such file or directory\n", str);
}

void	make_data(t_bige_node *bignode)
{
	int			size;
	t_data		*thedata;
	t_bige_node	*tmp;
	t_psr		*tmp2;
	int			i = 0;
	int			m = 0;

	size = node_size(bignode);
	tmp = bignode;
	tmp2 = bignode->psr;
	printf("size = %d\n", size);
	thedata = malloc(size * sizeof(t_data));
	while(tmp)
	{
		thedata[i].str = NULL;
		while(tmp->psr)
		{
			if (tmp->psr->tkn_st->e_type == CMD)
			{
				thedata[i].str = cmd_tab(thedata[i].str, tmp->psr->tkn_st->val);
				if (tmp->psr->nx_tkn && tmp->psr->tkn_st->e_type == CMD && tmp->psr->nx_tkn->tkn_st->e_type == ARG)
					thedata[i].str = cmd_tab(thedata[i].str, tmp->psr->nx_tkn->tkn_st->val);
			}
			if (tmp->psr->tkn_st->e_type == INF)
			{
				check_file(tmp->psr->tkn_st->val);
			}
			tmp->psr = tmp->psr->nx_tkn;
		}
		i++;
		tmp = tmp->psr_next;
	}
	i = 0;
	while(i < size)
	{
		while (thedata[i].str[m])
		{
			printf("CMD[%d] = | %s |\n", m, thedata[i].str[m]);
			m++;
		}
		i++;
		m = 0;
	}
}

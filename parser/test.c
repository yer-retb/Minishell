/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:55:10 by enja              #+#    #+#             */
/*   Updated: 2022/10/23 02:27:41 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	number_of_arg(t_psr *head)
{
	int		i;
	t_psr	*save;

	i = 0;
	save = head;
	while (save)
	{
		save = save->nx_tkn;
		i++;
		printf("%d\n",i);
	}
	
	return (i);
}

void    check_file(char *str)
{
    int fd;
    fd = access(str, F_OK);
    if (fd == -1)
        printf("Minishell: %s: no such file or directory\n", str);
}

t_red	*red_list(int type, char *val)
{
	t_red	*red;
	red = malloc(sizeof(t_red));
	red->next = NULL;
	if (type == INF)
	{
		red->file = val;
		check_file(val);
		red->fd = open(val, O_RDONLY);
	}
	else if (type == OUTF)
	{
		red->file = val;
		red->fd = open(val, O_CREAT | O_RDWR, 0644);
	}
	else if (type == HRD)
	{
		red->file = val;
		red->fd = open(val, O_RDWR, 0644);
	}
	else if (type == APD)
	{
		red->file = val;
		red->fd = open(val, O_CREAT | O_RDWR, 0644);
	}
	return (red);
}

t_data	big_data(t_psr *node)
{
	t_data	data;
	t_red	*hd_red;
	t_red	*tmp;

	hd_red = NULL;
	tmp = NULL;
	data.red = NULL;
	data.str = NULL;
	
	// printf("[%s]\n", node->tkn_st->val);
	while (node)
	{
		if ((node->tkn_st->e_type == CMD || node->tkn_st->e_type == ARG))
			data.str = cmd_tab(data.str, node->tkn_st->val);
		else if ((node->tkn_st->e_type == INF) || (node->tkn_st->e_type == OUTF) \
			|| (node->tkn_st->e_type == HRD) || (node->tkn_st->e_type == APD))
		{
			if (!hd_red)
			{
				hd_red = red_list(node->tkn_st->e_type, \
					node->tkn_st->val);
				// printf("RED %s\n", hd_red->file);
			}
			else
			{
				tmp = hd_red;
				while (tmp && tmp->next)
					tmp = tmp->next;
				tmp->next = red_list(node->tkn_st->e_type, \
					node->tkn_st->val);
				// printf("RED %s\n", tmp->file);
			}
		}
		node = node->nx_tkn;
	}
	if (hd_red)
		data.red = hd_red;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:55:10 by enja              #+#    #+#             */
/*   Updated: 2022/11/11 04:55:27 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include <fcntl.h>

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
	}
	return (i);
}

int	check_file(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
	{
		printf("Minishell: %s: no such file or directory\n", str);
		return (0);
	}
	return (1);
}

t_red	*red_list(int type, char *val, int *flag)
{
	t_red	*red;

	red = malloc(sizeof(t_red));
	red->next = NULL;
	if (type == INF)
	{
		red->type = type;
		red->file = val;
		if (!check_file(val))
			*flag = -1;
		red->fd = open(val, O_RDONLY);
	}
	else if (type == OUTF)
	{
		red->type = type;
		red->file = val;
		red->fd = open(val, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else if (type == HRD)
	{
		red->type = type;
		red->file = val;
	}
	else if (type == APD)
	{
		red->type = type;
		red->file = val;
		red->fd = open(val, O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	printf("----> %d\n", red->fd);
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
	data.flag = 0;
	data.in = 0;
	data.out = 1;
	while (node && (data.flag == 0))
	{
		if ((node->tkn_st->e_type == CMD || node->tkn_st->e_type == ARG))
			data.str = cmd_tab(data.str, node->tkn_st->val);
		else if ((node->tkn_st->e_type == INF) || (node->tkn_st->e_type == OUTF) \
			|| (node->tkn_st->e_type == HRD) || (node->tkn_st->e_type == APD))
		{
			if (!hd_red)
			{
				hd_red = red_list(node->tkn_st->e_type, \
					node->tkn_st->val, &data.flag);
				if (hd_red->type == OUTF || hd_red->type == APD)
					data.out = hd_red->fd;
				else if (hd_red->type == INF)
					data.in = hd_red->fd;
			}
			else
			{
				tmp = hd_red;
				while (tmp && tmp->next)
				{
					close(tmp->fd);
					tmp = tmp->next;
				}
				tmp->next = red_list(node->tkn_st->e_type, \
					node->tkn_st->val, &data.flag);
				if (tmp->next->type == OUTF || tmp->next->type == APD)
					data.out = tmp->next->fd;
				else if (tmp->next->type == INF)
					data.in = tmp->next->fd;
			}
		}
		node = node->nx_tkn;
	}
	if (hd_red)
		data.red = hd_red;
	return (data);
}

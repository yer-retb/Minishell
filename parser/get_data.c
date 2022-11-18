/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:01:54 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/17 06:39:29 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include <fcntl.h>

void	outf_hrd(t_red **red, char *val, int type)
{
	if (type == OUTF)
	{
		put_red(red, val, type);
		(*red)->fd = open(val, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else if (type == HRD)
	{
		put_red(red, val, type);
		(*red)->fd = open("/tmp/.herdock", O_RDONLY | O_TRUNC, 0644);
	}
}

t_red	*red_list(int type, char *val, int *flag)
{
	t_red	*red;

	red = ft_malloc(sizeof(t_red));
	red->next = NULL;
	if (!val)
	{
		*flag = -1;
		ambiguous_redirect();
	}
	else if (type == INF && *flag == 0)
	{
		put_red(&red, val, type);
		if (!check_file(val))
			*flag = -1;
		red->fd = open(val, O_RDONLY);
	}
	else if ((type == OUTF || type == HRD) && *flag == 0)
		outf_hrd(&red, val, type);
	else if (type == APD && *flag == 0)
	{
		put_red(&red, val, type);
		red->fd = open(val, O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	return (red);
}

void	first_red(t_red **hd_red, t_psr **node, t_data *data)
{
	(*hd_red) = red_list((*node)->tkn_st->e_type, \
		(*node)->tkn_st->val, &data->flag);
	if ((*hd_red)->type == OUTF || (*hd_red)->type == APD)
		(*data).out = (*hd_red)->fd;
	else if ((*hd_red)->type == INF)
		(*data).in = (*hd_red)->fd;
}

void	last_red(t_red **hd_red, t_psr **node, t_data *data)
{
	t_red	*tmp;

	tmp = *hd_red;
	while (tmp && tmp->next)
	{
		close(tmp->fd);
		tmp = tmp->next;
	}
	tmp->next = red_list((*node)->tkn_st->e_type, \
		(*node)->tkn_st->val, &data->flag);
	if (tmp->next->type == OUTF || tmp->next->type == APD)
		(*data).out = tmp->next->fd;
	else if (tmp->next->type == INF)
		(*data).in = tmp->next->fd;
}

t_data	big_data(t_psr *node)
{
	t_data	data;
	t_red	*hd_red;

	hd_red = NULL;
	data.red = NULL;
	data.str = NULL;
	data.flag = 0;
	data.out = 1;
	while (node)
	{
		if ((node->tkn_st->e_type == CMD || node->tkn_st->e_type == ARG))
			data.str = cmd_tab(data.str, node->tkn_st->val);
		else if ((node->tkn_st->e_type == INF) || (node->tkn_st->e_type == OUTF)
			|| (node->tkn_st->e_type == HRD) || (node->tkn_st->e_type == APD))
		{
			if (!hd_red)
				first_red(&hd_red, &node, &data);
			else
				last_red(&hd_red, &node, &data);
		}
		node = node->nx_tkn;
	}
	if (hd_red)
		data.red = hd_red;
	return (data);
}

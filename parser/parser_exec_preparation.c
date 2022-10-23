/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_preparation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:51:45 by enja              #+#    #+#             */
/*   Updated: 2022/10/23 02:37:20 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check(char *str)
{
	if (ft_strcmp(str, ">") && ft_strcmp(str, "<") && \
		ft_strcmp(str, ">>") && ft_strcmp(str, "<<"))
		return (1);
	return (0);
}

t_bige_node	*asing_tk2(t_psr *hd, t_bige_node *bignode)
{
	bignode = malloc(sizeof(t_bige_node));
	bignode->psr = hd;
	bignode->psr_next = NULL;
	return (bignode);
}

t_tkn	*asing_tk(t_tkn *tkn, char *val, int type)
{
	tkn = malloc(sizeof(t_tkn));
	tkn->e_type = type;
	tkn->val = val;
	return (tkn);
}

void	add_list_at_back3(t_bige_node **save, t_bige_node *node)
{
	t_bige_node	*head;

	head = *save;
	if (head == NULL)
	{
		*save = node;
		return ;
	}
	while (head->psr_next)
	{
		head = head->psr_next;
	}
	head->psr_next = node;
	node->psr_next = NULL;
}

t_bige_node	*parser_tokenazer(char **tab, t_psr *hd)
{
	int		i;
	t_tkn	*tk = NULL;
	t_bige_node *bignode = NULL;
	i = 0;
	while(tab[i])
	{
		if (ft_strcmp(tab[i], ">") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], OUTF)));
		else if (ft_strcmp(tab[i], ">>") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], APD)));
		else if (ft_strcmp(tab[i], "<<") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], HRD)));
		else if (ft_strcmp(tab[i], "<") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], INF)));
		else if (tab[i][0] == '|')
		{
			add_list_at_back3(&bignode, asing_tk2(hd, bignode));
			hd = NULL;
		}
		else
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[i], ARG)));
		i++;
	}
	add_list_at_back3(&bignode, asing_tk2(hd, bignode));
	return(bignode);
}

int	count_node(t_bige_node *node)
{
	t_bige_node	*save;
	int			i;

	save = node;
	i = 1;
	while (node->psr_next)
	{
		node = node->psr_next;
		i++;
	}
	node = save;
	return (i);
}

void	parser_exec_preparation(char **tab, t_psr *hd)
{
	t_bige_node *bignode;
	t_bige_node	*tmp;
	// t_data		*data;
	// int			i;
	// int			j;
	// int			 k = 0;
	bignode = parser_tokenazer(tab, hd); 
	tmp = bignode;
	while (tmp)
	{
		while (tmp->psr)
		{
			printf("value = [ %s ] token = [ %d ]\n", tmp->psr->tkn_st->val, tmp->psr->tkn_st->e_type);
			 tmp->psr = tmp->psr->nx_tkn;
		}
		tmp = tmp->psr_next;
	}

	// 	i = count_node(bignode);
	// 	j = 0;
	// 	data = malloc(sizeof(t_data) * i);
	// 	while (bignode)
	// 	{
	// 		data[j] = big_data(bignode->psr);
	// 		bignode = bignode->psr_next;
	// 		j++;
	// 	}
	// 	j = 0;
	// 	while (k < i)
	// 	{
	// 		j = 0;
	// 		while (data[k].str && data[k].str[j])
	// 		{
	// 			printf("CMD[%d] : %s\n", j, data[k].str[j]);
	// 			j++;
	// 		}
	// 		k++;
	// 	}
	// 	k = 0;
	// 	while (k < i)
	// 	{
	// 		while (data[k].red)
	// 		{
	// 			printf("-> RED %s\n", data[k].red->file);
	// 			data[k].red = data[k].red->next;
	// 		}
	// 		k++;
	// 	}
	}

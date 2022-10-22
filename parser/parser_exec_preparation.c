/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_preparation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:51:45 by enja              #+#    #+#             */
/*   Updated: 2022/10/22 01:30:26 by enja             ###   ########.fr       */
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
	t_psr	*head;
	t_bige_node *bignode = NULL;
	t_bige_node *save;
	i = 0;
	while(tab[i])
	{
		if (ft_strcmp(tab[i], ">") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], INF)));
		else if (ft_strcmp(tab[i], ">>") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], APD)));
		else if (ft_strcmp(tab[i], "<<") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], HRD)));
		else if (ft_strcmp(tab[i], "<") == 0)
			add_list_at_back2(&hd, init_node2(asing_tk(tk, tab[++i], OUTF)));
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
	// if (!bignode)
	// 	bignode = asing_tk2(hd, bignode);
	i = 0;
	save = bignode;
	head = bignode->psr;
	while (save)
	{
		while(save->psr)
		{
			if (save->psr->tkn_st->e_type == ARG)
			{
				save->psr->tkn_st->e_type = CMD;
				break ;
			}
			save->psr = save->psr->nx_tkn;
		}
		save = save->psr_next;
	}
	bignode->psr = head;
	return(bignode);
}

void	parser_exec_preparation(char **tab, t_psr *hd)
{
	t_bige_node *bignode;
	bignode = parser_tokenazer(tab, hd);
	
	while (bignode)
	{
		if (!bignode->psr)
			printf("heilll\n");
		while (bignode->psr)
		{
			printf("value = [ %s ] token = [ %d ]\n", bignode->psr->tkn_st->val, bignode->psr->tkn_st->e_type);
			 bignode->psr = bignode->psr->nx_tkn;
		}
		bignode = bignode->psr_next;
	}
}

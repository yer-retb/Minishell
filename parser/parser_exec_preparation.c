/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_preparation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:51:45 by enja              #+#    #+#             */
/*   Updated: 2022/11/12 22:24:55 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_bige_node	*tokenazer_utils(char **tab, t_psr *hd)
{
	t_tkn		*tk;
	t_bige_node	*bignode;

	tk = NULL;
	bignode = NULL;
	return (parser_tokenazer(tab, hd, tk, bignode));
}

t_bige_node	*parser_tokenazer(
				char **tab, t_psr *hd, t_tkn *tk, t_bige_node *bignode)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (tab && tab[i++])
		len++;
	i = 0;
	while (i < len)
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
	return (bignode);
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

void	*parser_exec_preparation(char **tab, t_psr *hd)
{
	t_bige_node	*bignode;
	t_bige_node	*tmp;
	t_data		*data;
	int			i;
	int			j;

	bignode = tokenazer_utils(tab, hd);
	tmp = bignode;
	i = count_node(bignode);
	j = 0;
	data = malloc(sizeof(t_data) * i);
	while (bignode)
	{
		data[j] = big_data(bignode->psr);
		data[j].in = 0;
		bignode = bignode->psr_next;
		j++;
	}
	data[0].size = i;
	return (data);
}

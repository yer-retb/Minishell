/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_preparation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:17 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/18 00:21:33 by yer-retb         ###   ########.fr       */
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

int	ft_len(char **tab)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (tab && tab[i++])
		len++;
	return (len);
}

t_bige_node	*parser_tokenazer(
				char **tab, t_psr *hd, t_tkn *tk, t_bige_node *bignode)
{
	int	i;

	i = 0;
	while (i < ft_len(tab))
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
	data = ft_malloc(sizeof(t_data) * i);
	while (bignode)
	{
		data[j] = big_data(bignode->psr);
		bignode = bignode->psr_next;
		j++;
	}
	data[0].size = i;
	g_b.s_size = i;
	return (data);
}

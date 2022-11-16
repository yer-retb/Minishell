/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_more_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:51 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 05:46:31 by yer-retb         ###   ########.fr       */
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
	bignode = ft_malloc(sizeof(t_bige_node));
	bignode->psr = hd;
	bignode->psr_next = NULL;
	return (bignode);
}

t_tkn	*asing_tk(t_tkn *tkn, char *val, int type)
{
	tkn = ft_malloc(sizeof(t_tkn));
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

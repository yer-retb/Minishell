/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:21:43 by enja              #+#    #+#             */
/*   Updated: 2022/10/05 13:00:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	**init_env(char **env, char **my_env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	my_env = malloc(sizeof (char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

t_parser	*start_lexing(char *cmd, t_token *tk, t_parser *hd)
{
	t_lexer		*lexer;

	hd = NULL;
	lexer = init_lexer(cmd);
	tk = lexer_get_next_token(lexer);
	if (!tk)
		return (NULL);
	while (tk != NULL)
	{
		add_list_at_back(&hd, init_node(tk));
		tk = lexer_get_next_token(lexer);
	}
	return (hd);
}

void	init_shell(char **my_env)
{
	char		*cmd;
	t_token		*token;
	t_parser	*head;
	t_parser	*nhd;
	char		**tab;
	int i = 0;
	token = NULL;
	while (TRUE)
	{
		cmd = get_prompt();
		if (ft_strcmp(cmd, "exit") == 0)
			exit(1);
		if (ft_strcmp(cmd, "clear") == 0)
		{
			clear_prompt();
			continue ;
		}
		head = start_lexing(cmd, token, head);
		if (!head)
			continue ;
		tab = parser_get(head, my_env);
		if (!tab)
		{
			while (head)
			{
				free(head->token_struct);
				head = head->next_token;
			}
		}
		nhd = head;
		while (head)
		{
			printf("type = %d value = %s\n",
				head->token_struct->e_type, head->token_struct->value);
			head = head->next_token;
		}
		while (nhd)
		{
			free(nhd->token_struct);
			nhd = nhd->next_token;
		}
		while (tab[i])
			printf("%s\n", tab[i++]);
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
		free(cmd);
		i = 0;
	}
}
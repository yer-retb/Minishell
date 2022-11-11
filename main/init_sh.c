/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:21:43 by enja              #+#    #+#             */
/*   Updated: 2022/11/11 00:18:35 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

char	**init_env(t_env *last_env)
{
	int		i;
	t_env	*env;

	env = last_env;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	env = last_env;
	g_b.my_env = malloc(sizeof (char *) * (i + 1));
	i = 0;
	while (env)
	{
		g_b.my_env[i] = ft_strjoin_no_free \
			(ft_strjoin_no_free(env->name, "="), env->path);
		i++;
		env = env->next;
	}
	g_b.my_env[i] = NULL;
	return (g_b.my_env);
}

t_parser	*start_lexing(char *cmd, t_token *tk, t_parser *hd)
{
	t_lexer		*lexer;

	hd = NULL;
	lexer = init_lexer(cmd);
	tk = lexer_get_next_token(lexer);
	if (tk && tk->e_type == EROR)
	{
		free(lexer);
		return (NULL);
	}
	while (tk != NULL)
	{
		add_list_at_back(&hd, init_node(tk));
		tk = lexer_get_next_token(lexer);
		if (tk && tk->e_type == EROR)
		{
			free(lexer);
			return (NULL);
		}
	}
	free(lexer);
	return (hd);
}

void	init_shell(t_env *last_env)
{
	char		*cmd;
	t_token		*token;
	t_parser	*head = NULL;
	t_parser	*nhd;
	t_psr		*nhead = NULL;
	char		**tab;
	t_data		*data;

	int i = 0;
	token = NULL;
	while (TRUE)
	{
		g_b.my_env = init_env(last_env);
		cmd = get_prompt();
		if (cmd == NULL)
		{
			free(cmd);
			exit (0); // must set the last exit value;
		}
		head = start_lexing(cmd, token, head);
		if (!head)
		{
			free(cmd);
			nhd = head;
			t_parser	*tmp;
			while (nhd)
			{
				free(nhd->token_struct->value);
				free(nhd->token_struct);
				tmp = nhd->next_token;
				free(nhd);
				nhd = tmp;
			}
			free(nhd);
			continue ;
		}
		tab = parser_get(head, g_b.my_env);
		if (!tab)
		{
			free(cmd);
			nhd = head;
			t_parser	*tmp;
			while (nhd)
			{
				free(nhd->token_struct->value);
				free(nhd->token_struct);
				tmp = nhd->next_token;
				free(nhd);
				nhd = tmp;
			}
			free(nhd);
			continue ;
		}
		nhd = head;
		t_parser	*tmp;
		while (nhd)
		{
			free(nhd->token_struct->value);
			free(nhd->token_struct);
			tmp = nhd->next_token;
			free(nhd);
			nhd = tmp;
		}
		free(nhd);
		i = 0;
		data = parser_exec_preparation(tab, nhead);
		builtins(&last_env, data);
		while (tab[i])
			free(tab[i++]);
		free(tab);
		free(cmd);
		i = 0;
	}
}

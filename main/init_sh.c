/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:01:01 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:39:03 by yer-retb         ###   ########.fr       */
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
	g_b.my_env = ft_malloc(sizeof (char *) * (i + 1));
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

void	ft_free(t_parser **head, char **cmd)
{
	t_parser	*nhd;
	t_parser	*tmp;

	nhd = *head;
	while (nhd)
	{
		free(nhd->token_struct->value);
		free(nhd->token_struct);
		tmp = nhd->next_token;
		free(nhd);
		nhd = tmp;
	}
	free(nhd);
	free(*cmd);
}

int	ft_norm(t_token **token, char **cmd, t_parser **head, t_env **last_env)
{
	g_b.my_env = init_env(*last_env);
	*cmd = get_prompt();
	if (*cmd == NULL)
	{
		printf("exit\n");
		exit (g_b.exit_val);
	}
	*head = start_lexing(*cmd, *token, *head);
	if (!head)
	{
		ft_free(head, cmd);
		return (0);
	}
	return (1);
}

void	init_shell(t_env *last_env)
{
	t_token		*token;
	t_parser	*head;
	char		**tab;
	t_data		*data;

	head = NULL;
	while (TRUE)
	{
		g_b.i = 0;
		if (!ft_norm(&token, &g_b.cmd, &head, &last_env))
			continue ;
		tab = parser_get(head, g_b.my_env);
		if (!tab)
		{
			ft_free(&head, &g_b.cmd);
			continue ;
		}
		ft_free(&head, &g_b.cmd);
		data = parser_exec_preparation(tab, g_b.nhead);
		if (!excut_herdoc(data))
			if (free_tab(tab))
				continue ;
		builtins(&last_env, data);
		free_tab(tab);
	}
}

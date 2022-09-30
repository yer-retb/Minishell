/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/30 23:48:57 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(int ac, char **av, char **env)
{
	char		*cmd;
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;
	char		**my_env;

	head = NULL;
	(void) ac;
	(void) av;
	int i = 0;
	my_env = NULL;
	while(env[i])
		i++;
	my_env = malloc(sizeof (char*) * i);
	i = 0;
	while(env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	while (TRUE)
	{
		cmd = get_prompt();
		if (ft_strcmp(cmd, "exit") == 0)
			exit(1);
		if (ft_strcmp(cmd, "clear") == 0)
			clear_prompt();
		lexer = init_lexer(cmd);
		token = NULL;
		if (fork() == 0)
		{
			token = lexer_get_next_token(lexer);
			while (token != NULL)
			{
				add_list_at_back(&head, init_node(token));
				token = lexer_get_next_token(lexer);
			}
			parser_get(head, my_env);
			while (head)
			{
				printf("type = %d value = %s\n",
					head->token_struct->e_type, head->token_struct->value);
				head = head->next_token;
			}

			/********* hada matedich 3lih *********/
			// save = init_list(cmd);
			// ls = get_next_list(save);
			// while (ls != NULL)
			// {
			// 	printf("(%s)\n", ls->file);
			// 	ls = get_next_list(save);
			// }
			/***************************************/
			
			// printf ("ok\n");
			// freii hna
			exit(1);
		}

		wait(NULL);
		free(lexer->content);
		free(lexer);
	}
}

// int main()
// {
// 	char		*cmd;
// 	t_lexer		*lexer;
// 	t_token		*token;
// 	t_parser	*head;

// 	while (1)
// 	{
// 		cmd = readline("\033[0;32m[\033[0m minishell \033[0;32m]~>\033[0m ");
// 		add_history(cmd);
// 		lexer = init_lexer(cmd);
// 		token = NULL;
// 		token = lexer_get_next_token(lexer);
// 		while (token != NULL)
// 		{
// 			add_list_at_back(&head, init_node(token));
// 			token = lexer_get_next_token(lexer);
// 		}
// 		parser_get(head);
// 		while (head)
// 		{
// 			printf("type = %d value = %s\n",
// 				head->token_struct->e_type, head->token_struct->value);
// 			head = head->next_token;
// 		}
// 		free (cmd);
// 	}
// }
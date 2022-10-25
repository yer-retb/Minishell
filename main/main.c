/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/10/25 03:11:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(int ac, char **av, char **env)
{
	// char		*cmd;
	// t_lexer		*lexer;
	// t_token		*token;
	// t_parser	*head;
	char		**my_env;
	// head = NULL;
	(void) ac;
	(void) av;
	(void) env;
	my_env = NULL;
	my_env = init_env(env, my_env);
	init_shell(my_env);
	// while (TRUE)
	// {
	// 	cmd = get_prompt();
	// 	if (ft_strcmp(cmd, "exit") == 0)
	// 		exit(1);
	// 	if (ft_strcmp(cmd, "clear") == 0)
	// 		clear_prompt();
	// 	lexer = init_lexer(cmd);
	// 	token = NULL;
	// 	token = lexer_get_next_token(lexer);
	// 	if (!token)
	// 		continue ;
	// 	while (token != NULL)
	// 	{
	// 		add_list_at_back(&head, init_node(token));
	// 		token = lexer_get_next_token(lexer);
	// 	}
	// 	if (!parser_get(head, my_env))
	// 	{
	// 		free(lexer->content);
	// 		free(lexer);
	// 		while (head)
	// 		{
	// 			free(head->token_struct);
	// 			head = head->next_token;
	// 		}
	// 		continue ;
	// 	}
	// 	while (head)
	// 	{
	// 		printf("type = %d value = %s\n",
	// 			head->token_struct->e_type, head->token_struct->value);
	// 		head = head->next_token;
	// 	}
	// }
}

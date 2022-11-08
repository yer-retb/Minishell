/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/07 16:19:51 by yer-retb         ###   ########.fr       */
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
	t_env		*last_env;
	// head = NULL;
	(void) ac;
	(void) av;
	// (void) env;
	if(!env[0])
		printf("ffffff\n");
	my_env = NULL;
	last_env = envirement_list(env);
	if(last_env)
		printf("EEEEE\n");
	init_shell(my_env, last_env);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/20 05:48:51 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(void)
{
	char		*cmd;
	t_lexer		*lexer;
	t_token		*token;
	t_parser	*head;

	head = NULL;
	while (TRUE)
	{
		cmd = get_prompt();
		if (ft_strcmp(cmd, "exit") == 0)
			exit(1);
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
			parser_get(head);
			while (head)
			{
				printf("type = %d value = %s\n",
					head->token_struct->e_type, head->token_struct->value);
				head = head->next_token;
			}
			// printf ("ok\n");
			//freii hna
			exit(1);
		}
		wait(NULL);
		free(lexer->content);
		free(lexer);
	}
}

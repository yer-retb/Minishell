/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/19 06:08:02 by enja             ###   ########.fr       */
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
		// if (cmd[0] == '\0')
		// 	continue ;
		if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
			exit(1);
		lexer = init_lexer(cmd);
		token = NULL;
		if (fork() == 0)
		{
			while ((token = lexer_get_next_token(lexer)) != NULL)
				add_list_at_back(&head, init_node(token));
			parser_get(head);
			// while (head)
			// {
			// 	printf("type = %d value = %s\n",head->token_struct->e_type, head->token_struct->value);
			// 	head = head->next_token;
			// }
			// printf ("ok\n");
			//freii hna
			exit(1);
		}
		wait(NULL);
		free(lexer->content);
		free(lexer);
	}
}

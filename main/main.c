/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/18 05:34:03 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(void)
{
	char		*cmd;
	t_lexer		*lexer;
	t_token		*token;
	// t_parser	*head;

	while (TRUE)
	{
		cmd = get_prompt();
		// if (cmd[0] == '\0')
		// 	continue ;
		// if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
		lexer = init_lexer(cmd);
		token = NULL;
		if (fork() == 0)
		{
			while ((token = lexer_get_next_token(lexer)) != NULL)
			{
				//head = add_list_at_back(head, init_node(token));
				printf("TOKEN (%d ==> %s)\n", token->e_type, token->value);
			}
			// while (head->next_token)
			// {

			// 	printf("yes\n");
			// 	head = head->next_token;
			// }
			printf ("ok\n");
			exit(1);
		}
		wait(NULL);
	}
}

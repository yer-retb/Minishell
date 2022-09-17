/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 05:50:34 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 02:38:21 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(void)
{
	char	*cmd;
	t_lexer	*lexer;
	t_token	*token;

	while (TRUE)
	{
		cmd = get_prompt();
		break ;
	}
	lexer = init_lexer(cmd);
	token = NULL;
	while ((token = lexer_get_next_token(lexer)) != NULL)
		printf("TOKEN (%d ==> %s)\n", token->e_type, token->value);
	printf ("ok");
}

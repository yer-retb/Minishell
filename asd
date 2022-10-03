asd
asd
asd
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
	(void) env;
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
		token = lexer_get_next_token(lexer);
		if(!token)
			continue;
		while (token != NULL)
		{
			add_list_at_back(&head, init_node(token));
			token = lexer_get_next_token(lexer);
		}
		if (!parser_get(head, my_env))
		{
			free(lexer->content);
			free(lexer);
			while (head)
			{
				free(head->token_struct);
				head = head->next_token;
			}
			continue ;
		}
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
			// exit(1);
		// }
		// wait(NULL);
		// free(lexer->content);
		// free(lexer);
	}
}
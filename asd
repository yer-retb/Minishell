char	**parser_get_tab(t_parser *st_list)
{
	int			i;
	char		*newcmd;
	char		**cmd_table;
	t_parser	*head;

	cmd_table = malloc(1 * sizeof(char *));
	cmd_table[0] = NULL;
	newcmd = NULL;
	head = st_list;
	i = 0;
	while (head)
	{
		if (head->token_struct->value[i] == '\"' || head->token_struct->value[i] == '\'')
		{
			if (head->token_struct->value[i] == '\"')
			{
				i++;
				while (head->token_struct->value[i] && head->token_struct->value[i] != '\"')
					newcmd = get_char(newcmd, head->token_struct->value[i++]);
			}
			else if(head->token_struct->value[i] == '\'')
			{
				i++;
				while(head->token_struct->value[i] && head->token_struct->value[i] != '\'')
					newcmd = get_char(newcmd, head->token_struct->value[i++]);
			}
			i++;
			if (head->token_struct->value[i] == '\0')
			{
				cmd_table = cmd_tab(cmd_table, newcmd);
				head = head->next_token;
				newcmd = NULL;
				i = 0;
			}
		}
		else
		{
			while (head->token_struct->value[i] && head->token_struct->value[i] != '\"' && head->token_struct->value[i] != '\'')
				newcmd = get_char(newcmd, head->token_struct->value[i++]);
			if (head->token_struct->value[i] == '\0')
			{
				cmd_table = cmd_tab(cmd_table, newcmd);
				head = head->next_token;
				newcmd = NULL;
				i = 0;
			}
		}
	}
	return(cmd_table);
}
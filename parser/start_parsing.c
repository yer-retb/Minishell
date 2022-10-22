// /* ************************************************************************** */
// /*                                                                            */
// /*                                                                            */
// /*				had lfile howa bach kent kan7ayed l COTT o DOUBEL COTS     	  */
// /* 				 matediich 3liiih mohim khellih ne9edro ne7tajoh              */
// /*                  men be3d rah howa li mcomonter f main					  */
// /*                                                                            */
// /* ************************************************************************** */




// #include "../include/include.h"

// t_list	*init_list(char *cmd)
// {
// 	t_list	*list;

// 	list = malloc(sizeof(t_list));
// 	list->command = cmd;
// 	list->i = 0;
// 	list->c = cmd[list->i];
// 	return (list);
// }

// void	list_advence(t_list *list)
// {
// 	if (list->c != '\0' && list->i < ft_strlen(list->command))
// 	{
// 		list->i += 1;
// 		list->c = list->command[list->i];
// 	}
// }

// void	list_skip_space(t_list *list)
// {
// 	while (list->c == ' ' || list->c == '\t')
// 		list_advence(list);
// }

// t_red	*get_next_list(t_list *list)
// {
// 	while (list->c != '\0' && list->i < ft_strlen(list->command))
// 	{
// 		if (list->c == ' ' || list->c == '\t')
// 			list_skip_space(list);
// 		if (list->c == '\'' || list->c == '\"')
// 			return(list_collect(list, list->c));
// 		if (list->c != '\0' && ft_isascii(list->c)
// 			&& (!(is_rederection(list->c))))
// 			return(list_cmd_collect(list));
// 	}
// 	return (NULL);
// }

// t_red	*list_cmd_collect(t_list *list)
// {
// 	char	*value;
// 	char	*str;

// 	value = NULL;
// 	while (list->c != '\0' && (!(is_rederection(list->c)))
// 		&& list->c != ' ' && list->c != '\t')
// 	{
// 		str = list_get_c_as_str(list);
// 		value = ft_strjoin(value, str);
// 		list_advence(list);
// 	}
// 	return (my_cmd(ARG, value));
// }

// t_red	*list_collect(t_list *list, char qut)
// {
// 	char	*value;
// 	char	*str;

// 	value = NULL;
// 	list_advence(list);
// 	while(list->c != '\0')
// 	{
// 		if (list->c == qut)
// 		{
// 			if (remove_quats(list, &qut))
// 				return(my_cmd(CMD, value));
// 		}
// 		str = list_get_c_as_str(list);
// 		value = ft_strjoin(value, str);
// 		list_advence(list);
// 	}
// 	return (NULL);
// }

// int	remove_quats(t_list *list, char *d)
// {
// 	list_advence(list);
// 	if (list->c == '\'')
// 	{
// 		if (d[0] == '\"')
// 			d[0] = '\'';
// 		while (list->c == '\'' || list->c == '\"')
// 			list_advence(list);
// 		return (0);
// 	}
// 	else if (list->c == '\"')
// 	{
// 		if (d[0] == '\'')
// 			d[0] = '\"';
// 		while (list->c == '\'' || list->c == '\"')
// 			list_advence(list);
// 		return (0);
// 	}
// 	return (1);
// }

// t_red	*my_cmd(int typ, char *file)
// {
// 	t_red	*red;

// 	red = malloc(sizeof(t_red));
// 	red->e_red_typ = typ;
// 	red->file = file;
// 	return (red);
// }

// char	*list_get_c_as_str(t_list *list)
// {
// 	char	*str;

// 	str = malloc(sizeof(char) * 2);
// 	str[0] = list->c;
// 	str[1] = '\0';
// 	return (str);
// }

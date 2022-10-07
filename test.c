#include <stdio.h>
#include <stdlib.h>
int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	tdm(char **arr)
{
	int	a;

	a = 0;
	while (arr[a] != NULL)
		a++;
	return (a);
}

char	*get_char(char *str, char c)
{
	char	*strnw;
	int		i;

	i = 0;
	if (!str)
	{
		str = malloc (sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	strnw = malloc((ft_strlen(str) + 2) * sizeof(char));
	while (str[i])
	{
		strnw[i] = str[i];
		i++;
	}
	strnw[i++] = c;
	strnw[i] = '\0';
	return (strnw);
}

char	**cmd_tab(char **cmd_table, char *newcmd)
{
	int		i;
	char	**newtable;

	i = 0;
	if (!cmd_table)
	{
		cmd_table = malloc(2 * sizeof(char *));
		cmd_table[0] = newcmd;
		cmd_table[1] = NULL;
		return (cmd_table);
	}
	newtable = malloc((tdm(cmd_table) + 2) * sizeof(char *));
	while (cmd_table[i])
	{
		newtable[i] = cmd_table[i];
		i++;
	}
	newtable[i++] = newcmd;
	newtable[i] = NULL;
	return (newtable);
}

int main()
{
	int i;
	char *str = "dsf dsfdsf hello sdfdsf";
	char *s = NULL;
	char **tb = NULL;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			s = get_char(s, str[i++]);
		tb = cmd_tab(tb, s);
		s = NULL;
	}
	i = 0;
	while (tb[i])
		printf("%s\n", tb[i++]);
}
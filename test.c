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
#include <unistd.h>
char  **ft_split1(char *str)
{
	int i;
	char *s = NULL;
	char **tb = NULL;
	//while(1);
	if (!str || !str[0])
	{
		tb = malloc(8);
		tb[0] = 0;
		return tb;
	}
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
	return (tb);
}


#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}
int main()
{
	char *s = "";
	char **str1 = ft_split1(s);
	for(int i = 0;str1[i];i++)
		printf("%s\n",str1[i]);
	printf("*********\n");
	/*char **str = ft_split(s);
	for(int i = 0;str[i];i++)
		printf("%s\n",str[i]);*/
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:09:13 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 20:29:10 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)

{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	check_len(char const *s, char c)

{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)

{
	char	**str;
	int		i;
	int		j;
	int		nb_word;
	int		len;

	if (!s)
		return (NULL);
	nb_word = ft_count_words(s, c);
	str = (char **)malloc ((nb_word + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (j < nb_word)
	{
		while (s[i] && s[i] == c)
			i++;
		len = check_len(s + i, c);
		str[j] = ft_substr(s, i, len);
		i += len;
		j++;
	}
	str[j] = NULL;
	return (str);
}

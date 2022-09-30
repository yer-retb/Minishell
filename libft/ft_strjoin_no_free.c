#include "libft.h"

char	*ft_strjoin_no_free(char *s1, char *s2)
{
	char	*final;
	int		len;
	int		n;
	int		i;

	if (!s1)
	{
		final = ft_strdup(s2);
		free (s2);
		return (final);
	}
	i = 0;
	n = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(len + 1);
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		final[i++] = s2[n++];
	}
	final[i] = '\0';
	return (final);
}

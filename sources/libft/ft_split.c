#include "../../includes/pipex.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = j;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	char	**temp;
	int		i;
	int		len;

	i = 0;
	temp = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!temp)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s != c && *s)
			{
				len++;
				s++;
			}
			temp[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	temp[i] = 0;
	return (temp);
}
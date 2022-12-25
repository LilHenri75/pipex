#include "../../includes/pipex_bonus.h"

char	*ft_nextline(char *line)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (line[i] == '\0')
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (0);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		temp[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_savenextlines(char *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (0);
	}
	temp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!temp)
		return (0);
	i++;
	while (save[i] != '\0')
		temp[j++] = save[i++];
	temp[j] = '\0';
	free(save);
	return (temp);
}

int	ft_linecheck(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_savefd(int fd, char *save)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	i = 1;
	while (ft_linecheck(save) == 0 && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (0);
		}
		temp[i] = '\0';
		save = ft_strjoin(save, temp);
	}
	free(temp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd == -1)
		return (0);
	save = ft_savefd(fd, save);
	if (!save)
		return (0);
	line = ft_nextline(save);
	save = ft_savenextlines(save);
	return (line);
}

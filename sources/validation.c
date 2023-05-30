/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:49:14 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/30 14:37:09 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_cmd_in_path(char **command, char **path, char *cmd, int execute)
{
	int		i;
	char	*tmp;

	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	i = 0;
	while (path && path[i] != NULL)
	{
		tmp = double_join(path, command, i);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int	is_cmd_valid(char *cmd, char **env)
{
	char	**command;
	char	**path;
	int		ret;

	ret = 0;
	path = NULL;
	if (cmd == NULL)
		return (ret);
	command = ft_split(cmd, ' ');
	path = ft_path_split(env);
	if (is_cmd_in_path(command, path, cmd, 0))
		ret = 1;
	if (path)
		ft_bigfree(command, path);
	return (ret);
}

char	*double_join(char **str, char **str2, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(str[i], "/");
	tmp2 = ft_strjoin(tmp, str2[0]);
	free(tmp);
	return (tmp2);
}

void	ft_bigfree(char **str, char **str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		free(str2[i]);
		i++;
	}
	free(str);
	free(str2);
}

char	**ft_path_split(char **env)
{
	int		i;
	char	**ret;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			ret = ft_split(env[i] + 5, ':');
			return (ret);
		}
		i++;
	}
	return (NULL);
}

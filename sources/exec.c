/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:50:45 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/24 01:59:18 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_cmd_valid(char *cmd, char **env)
{
	int		i;
	char	**command;
	char	**path;
	char	*tmp;

	i = 0;
	command = ft_split(cmd, ' ');
	path = ft_path_split(env);
	if (path == NULL)
		return (0);
	while (path[i] != NULL)
	{
		if (cmd[0] != '/')
			tmp = double_join(path, command, i);
		if (access(tmp, F_OK | X_OK) == 0 || access(cmd, F_OK | X_OK) == 0)
		{
			if (tmp)
				free(tmp);
			ft_bigfree(command, path);
			return (1);
		}
		if (cmd[0] != '/')
			free(tmp);
		i++;
	}
	ft_bigfree(command, path);
	return (0);
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

void	ft_execution(char *cmd, char **env)
{
    int		i;
	char	**command;
	char	**path;
	char	*tmp;

	i = 0;
	command = ft_split(cmd, ' ');
	path = ft_path_split(env);
	tmp = cmd;
	if (path == NULL)
		ft_printf("ERROR: no PATH variable found\n");
	while(path[i] != NULL)
	{
		if (cmd[0] != '/')
			tmp = double_join(path, command, i);
		if (access(tmp, F_OK | X_OK) == 0 || access(cmd, F_OK | X_OK) == 0)
		{
			execve(tmp, command, env);
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] != '/')
			free(tmp);
		i++;
	}
	ft_bigfree(command, path);
	ft_printf("ERROR: command not found: %s\n", cmd);
}

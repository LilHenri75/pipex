/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:50:45 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/30 14:36:06 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ex_direct(char **command, char *cmd, char **env)
{
	if (access(cmd, F_OK | X_OK) == 0)
	{
		execve(cmd, command, env);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	ex_path(char **command, char **path, char *cmd, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path && path[i] != NULL)
	{
		tmp = double_join(path, command, i);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			execve(tmp, command, env);
			exit(EXIT_SUCCESS);
		}
		free(tmp);
		i++;
	}
	return (0);
}

void	ft_execution(char *cmd, char **env)
{
	char	**com;
	char	**path;

	if (cmd == NULL)
	{
		ft_printf("ERROR: no command provided\n");
		exit(EXIT_FAILURE);
	}
	com = ft_split(cmd, ' ');
	path = ft_path_split(env);
	if (!ex_direct(com, cmd, env) && path && !ex_path(com, path, cmd, env))
		ft_printf("ERROR: command not found: %s\n", cmd);
	ft_bigfree(com, path);
}

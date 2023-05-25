/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:58:08 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/24 01:04:45 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
	while (path[i++])
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
	}
	ft_bigfree(command, path);
	ft_printf("ERROR: command not found: %s\n", cmd);
}

void	ft_exec_cmd(char *cmd, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_perror("ERROR:");
	pid = fork();
	if (pid == -1)
		ft_perror("ERROR:");
	if (pid == 0)
	{
		if (dup2(pipefd[0], 0) == -1)
			ft_perror("ERROR:");
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		if (dup2(pipefd[1], 1) == -1)
			ft_perror("ERROR:");
		close(pipefd[0]);
		ft_execution(cmd, env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:03 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/24 14:49:08 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	fchild;
	pid_t	schild;

	if (pipe(pipefd) == -1)
		ft_perror("ERROR");
	fchild = fork();
	if (fchild == -1)
		ft_perror("ERROR");
	if (fchild == 0)
		first_child(pipefd, argv, env);
	schild = fork();
	if (schild == -1)
		ft_perror("ERROR");
	if (schild == 0)
		second_child(pipefd, argv, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(fchild, NULL, 0);
	waitpid(schild, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		ft_printf("ERROR: wrong number of arguments\n");
	if (!is_cmd_valid(argv[2], env))
		ft_printf("ERROR: command not found: %s\n", argv[2]);
	if (!is_cmd_valid(argv[3], env))
		ft_printf("ERROR: command not found: %s\n", argv[3]);
	else
		ft_pipex(argc, argv, env);
	return (0);
}

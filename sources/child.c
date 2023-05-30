/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:53:56 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/24 00:56:06 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(int *pipefd, char **argv, char **env)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (dup2(input, 0) == -1)
		ft_perror("ERROR");
	if (dup2(pipefd[1], 1) == -1)
		ft_perror("ERROR");
	close(input);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_execution(argv[2], env);
}

void	second_child(int *pipefd, char **argv, char **env)
{
	int	output;

	output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (dup2(output, 1) == -1)
		ft_perror("ERROR");
	if (dup2(pipefd[0], 0) == -1)
		ft_perror("ERROR");
	close(output);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_execution(argv[3], env);
}

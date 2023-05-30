/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:47:03 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/30 14:47:09 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_argument_count(int argc)
{
	if (argc != 5)
	{
		ft_printf("ERROR: wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	validate_files(char *input_file, char *output_file)
{
	int	input;
	int	output;

	input = open(input_file, O_RDONLY);
	output = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (input == -1)
		ft_printf("ERROR: no such file or directory: %s\n", input_file);
	if (output == -1)
		ft_printf("ERROR: no such file or directory: %s\n", output_file);
	if (output == -1 || input == -1)
		exit(EXIT_FAILURE);
	close(input);
	close(output);
}

void	validate_commands(int argc, char **argv, char **env)
{
	int	i;
	int	valid;

	valid = 0;
	i = 2;
	while (i < argc - 1)
	{
		if (!is_cmd_valid(argv[i], env))
		{
			ft_printf("ERROR: command not found: %s\n", argv[i]);
			valid = 1;
		}
		i++;
	}
	if (valid == 1)
		exit(EXIT_FAILURE);
}

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
	check_argument_count(argc);
	validate_files(argv[1], argv[4]);
	validate_commands(argc, argv, env);
	ft_pipex(argc, argv, env);
	return (0);
}

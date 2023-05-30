/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:08:03 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/25 15:13:49 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	check_argument_count(int argc)
{
	if (argc < 5)
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

void ft_pipex(int argc, char **argv, char **env)
{
    int input;
    int output;
    int i;

    i = 2;
    input = open(argv[1], O_RDONLY);
    output = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (dup2(input, 0) == -1)
        ft_perror("ERROR:");
    while (i < argc - 2)
        ft_exec_cmd(argv[i++], env);
    if (dup2(output, 1) == -1)
        ft_perror("ERROR:");
    ft_execution(argv[argc - 2], env);
    close(output);
    close(input);
}

int	main(int argc, char **argv, char **env)
{
	check_argument_count(argc);
	validate_files(argv[1], argv[argc - 1]);
	validate_commands(argc, argv, env);
	ft_pipex(argc, argv, env);
	return (0);
}

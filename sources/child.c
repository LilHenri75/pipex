#include "../includes/pipex.h"

void    first_child(int *pipefd, char **argv, char **env)
{
    int input;

    input = open(argv[1], O_RDONLY);
    if (input == -1)
        ft_printf("ERROR: no such file or directory: %s\n", argv[1]);
    if (dup2(input, 0) == -1)
        ft_perror("ERROR");
    if (dup2(pipefd[1], 1) == -1)
        ft_perror("ERROR");
    close(pipefd[0]);
    close(pipefd[1]);
    close(input);
    ft_execution(argv[2], env);
}

void    second_child(int *pipefd, char **argv, char **env)
{
    int output;

    output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (output == -1)
        ft_printf("ERROR: no such file or directory: %s\n", argv[4]);
    if (dup2(output, 1) == -1)
        ft_perror("ERROR");
    if (dup2(pipefd[0], 0) == -1)
        ft_perror("ERROR");
    close(pipefd[0]);
    close(pipefd[1]);
    close(output);
    ft_execution(argv[3], env);
}
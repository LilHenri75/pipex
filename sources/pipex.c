#include "../includes/pipex.h"

void ft_pipex(int argc, char **argv, char **env)
{
    int pipefd[2];
    int fchild;
    int schild;

    if (pipe(pipefd) == -1)
        ft_perror("ERROR");
    fchild = fork();
    if (fchild == -1)
        ft_perror("ERROR");
    if (fchild == 0)
        first_child(pipefd, argv, env);
//    else
//        second_child(pipefd, argv, env);
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

int main(int argc, char **argv, char **env)
{
    if (argc != 5)
        ft_printf("ERROR: wrong number of arguments\n");
    ft_pipex(argc, argv, env);
    return (0);
}
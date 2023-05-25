#include "../includes/pipex_bonus.h"

int ft_fdopen(char *file, int flags)
{
    int fd;

    fd = -1;
    if (flags == 'H')
        fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
    else if (flags == 'I')
        fd = open(file, O_RDONLY);
    else if (flags == 'O')
        fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd == -1)
        ft_perror("ERROR:");
    return (fd);
}

void write_to_limiter(int *pipefd, char *limiter)
{
    char *line;

    close(pipefd[0]);
    ft_putstr_fd("heredoc: ", 1);
    while(get_next_line(0))
    {
        if(ft_strcmp(limiter, line) == 0)
        {
            free(line);
            close(pipefd[1]);
            exit(EXIT_SUCCESS);
        }
        ft_putstr_fd("heredoc: ", 1);
        if (write(pipefd[1], line, ft_strlen(line)) == -1)
            ft_perror("ERROR:");
        if (write(pipefd[1], "\n", 1) == -1)
            ft_perror("ERROR:");
        free(line);
    }
    free(line);
    close(pipefd[1]);
    ft_perror("ERROR:");
}

void ft_here_doc(int argc, char **argv)
{
    int pipefd[2];
    pid_t child;

    if (argc < 6)
        ft_printf("ERROR: wrong number of arguments\n");
    if (pipe(pipefd) == -1)
        ft_perror("ERROR:");
    child = fork();
    if (child == -1)
        ft_perror("ERROR:");
    if (child == 0)
        write_to_limiter(pipefd, argv[2]);
    else
    {
        close(pipefd[1]);
        if (dup2(pipefd[0], 0))
            ft_perror("ERROR:");
        close(pipefd[0]);
        waitpid(child, NULL, 0);
    }
}

void ft_pipex(int argc, char **argv, char **env)
{
    int fdin;
    int fdout;
    int i;

    if(ft_strcmp(argv[1], "here_doc") == 0)
    {
        i = 3;
        ft_here_doc(argc, argv);
        fdout = ft_fdopen(argv[argc - 1], 'H');
    }
    else
    {
        i = 2;
        fdin = ft_fdopen(argv[1], 'I');
        fdout = ft_fdopen(argv[argc - 1], 'O');
        if (dup2(fdin, 0) == -1)
            ft_perror("ERROR:");
    }
    while(i < argc - 2)
        ft_exec_cmd(argv[i++], env);
    if (dup2(fdout, 1) == -1)
        ft_perror("ERROR:");
    ft_execution(argv[argc - 2], env);
}

int main(int argc, char **argv, char **env)
{
    int i;

    i = 2;
    if (argc < 5)
        ft_printf("ERROR: wrong number of arguments\n");
    while (i < argc - 1)
    {
        if (!is_cmd_valid(argv[i], env))
            ft_printf("ERROR: command not found: %s\n", argv[i]);
        i++;
    }
    ft_pipex(argc, argv, env);
    return (0);
}
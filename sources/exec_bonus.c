#include "../includes/pipex_bonus.h"

char *double_join(char **str, char **str2, int i)
{
    char *tmp;

    tmp = ft_strjoin(str[i], "/");
    tmp = ft_strjoin(tmp, str2[0]);
    return (tmp);
}

void ft_bigfree(char **str, char **str2)
{
    int i;

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

char **ft_path_split(char **env)
{
    int i;
    char **ret;

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

void    ft_execution(char *cmd, char **env)
{
    int i;
    char **command;
    char **path;
    char *tmp;

    i = 0;
    command = ft_split(cmd, ' ');
    path = ft_path_split(env);
    tmp = cmd;
    if (path == NULL)
        ft_printf("ERROR: no PATH variable found\n");
    while(path[i])
    {
        if (cmd[0] != '/')
            tmp = double_join(path, command, i);
        if (access(tmp, F_OK | X_OK) == 0 || access(cmd, F_OK | X_OK) == 0 )
        {
            execve(tmp, command, env);
            exit(EXIT_SUCCESS);
        }
        if (cmd[0] != '/')
            free(tmp);
        i++;
    }
    write(1, "failure\n", 8);
    ft_bigfree(command, path);
    ft_printf("ERROR: command not found: %s\n", cmd);
}

void ft_exec_cmd(char *cmd, char **env)
{
    int     pipefd[2];
    pid_t   pid;

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
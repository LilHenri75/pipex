#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "./pipex.h"

//pipex

void ft_pipex(int argc, char **argv, char **env);
void ft_here_doc(int argc, char **argv);
void write_to_limiter(int *pipefd, char *limiter);
int ft_fdopen(char *file, int flags);
char *double_join(char **str, char **str2, int i);
void ft_bigfree(char **str, char **str2);
char **ft_path_split(char **env);
void    ft_execution(char *cmd, char **env);
void ft_exec_cmd(char *cmd, char **env);

//gnl

char	*get_next_line(int fd);

#endif

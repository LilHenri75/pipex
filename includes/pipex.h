#ifndef PIPEX_H
# define PIPEX_H

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

//pipex
void ft_pipex(int argc, char **argv, char **env);

//child
void first_child(int *pipefd, char **argv, char **env);
void second_child(int *pipefd, char **argv, char **env);

//exec
void ft_bigfree(char **str, char **str2);
void ft_execution(char *cmd, char **env);
char **ft_path_split(char **env);
char *double_join(char **str, char **str2, int i);

//libft
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void    ft_perror(char *str);


//ft_printf
int ft_print_char(int i);
int	ft_print_dec(int c);
int	ft_print_uns_dec(unsigned int c);
int	ft_print_string(char *s);
int	ft_print_uns_hexa_min(unsigned int c);
int	ft_print_uns_hexa_maj(unsigned int c);
int ft_print_hexa(unsigned long long c);
int	ft_argcheck(va_list *args, char c);
void ft_printf(const char *format, ...);

#endif

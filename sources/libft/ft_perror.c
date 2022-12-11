#include "../../includes/pipex.h"

void ft_perror(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}
# include "../../includes/pipex.h"

char *ft_strdup(const char *s)
{
    char    *temp;
    int     i;

    i = 0;
    temp = malloc(sizeof (char) * ft_strlen((char*) s) + 1);
    if (!temp)
        return(NULL);
    while(s[i])
    {
        temp[i] = (char) s[i];
        i++;
    }
    temp[i] = '\0';
    return (temp);
}
#include "../../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
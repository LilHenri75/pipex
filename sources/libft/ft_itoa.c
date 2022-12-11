#include "../../includes/pipex.h"

static int	ft_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long		nb;
	char		*temp;

	i = ft_length(n);
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	temp[i] = '\0';
	nb = n;
	if (nb == 0)
		temp[0] = '0';
	if (nb < 0)
	{
		temp[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		i--;
		temp[i] = nb % 10 + 48;
		nb /= 10;
	}
	return (temp);
}
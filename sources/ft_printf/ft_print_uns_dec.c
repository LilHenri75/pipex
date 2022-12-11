/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:30 by hebernar          #+#    #+#             */
/*   Updated: 2022/05/19 15:12:36 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*ft_unsigned_itoa(unsigned int n)
{
	int			i;
	char		*temp;
	
	if (n <= 4294967295 && n>= 1000000000)
		i = 10;
	else
		i = ft_length(n);
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	temp[i] = '\0';
	if (n == 0)
		temp[0] = '0';
	while (n != 0)
	{
		i--;
		temp[i] = n % 10 + 48;
		n /= 10;
	}
	return (temp);
}

int	ft_print_uns_dec(unsigned int c)
{
	char	*temp;
	int		i;

	temp = ft_unsigned_itoa(c);
	i = 0;

	while (temp[i] != '\0')
	{
		write(1, &temp[i], 1);
		i++;
	}
	free(temp);
	return(i);
}

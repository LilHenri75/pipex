/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:14:03 by hebernar          #+#    #+#             */
/*   Updated: 2022/05/19 15:50:20 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	base_count(unsigned long long c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		i++;
		c = c / 16;
	}
	return (i);
}

static void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, base);
		ft_putnbr_base(nbr % 16, base);
	}
	else
		write(1, &base[nbr % 16], 1);
}

int	ft_print_uns_hexa_min(unsigned int c)
{
	ft_putnbr_base(c, "0123456789abcdef");
	return (base_count(c));
}

int	ft_print_uns_hexa_maj(unsigned int c)
{
	ft_putnbr_base(c, "0123456789ABCDEF");
	return (base_count(c));
}

int ft_print_hexa(unsigned long long c)
{
	write(1, "0x", 2);
	ft_putnbr_base(c, "0123456789abcdef");
	return (base_count(c) + 2);
}
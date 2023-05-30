/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:59:37 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/25 14:43:44 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_argcheck(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = count + ft_print_char(va_arg(*args, int));
	else if (c == 's')
		count = count + ft_print_string(va_arg(*args, char *));
	else if (c == 'p')
		count = count + ft_print_hexa(va_arg(*args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count = count + ft_print_dec(va_arg(*args, int));
	else if (c == 'u')
		count = count + ft_print_uns_dec(va_arg(*args, unsigned int));
	else if (c == 'x')
		count = count + ft_print_uns_hexa_min(va_arg(*args, unsigned int));
	else if (c == 'X')
		count = count + ft_print_uns_hexa_maj(va_arg(*args, unsigned int));
	else if (c == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = i;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count = count + ft_argcheck(&args, format[i + 1]);
			i++;
		}
		else
		{		
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
}

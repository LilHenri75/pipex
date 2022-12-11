/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:14:06 by hebernar          #+#    #+#             */
/*   Updated: 2022/05/19 13:27:35 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_print_dec(int c)
{
	char	*temp;
	int		i;

	temp = ft_itoa(c);
	i = 0;
	while (temp[i] != '\0')
	{
		write(1, &temp[i], 1);
		i++;
	}
	free(temp);
	return(i);
}

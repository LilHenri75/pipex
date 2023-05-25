/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:50:49 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/25 14:54:45 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof (char) * ft_strlen((char *)s) + 1);
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = (char) s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:58:17 by hebernar          #+#    #+#             */
/*   Updated: 2023/05/25 14:58:18 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;
	size_t	end;

	if (!s)
		return (0);
	i = ft_strlen((char *)s);
	end = 0;
	if (start <= i)
		end = i - start;
	if (end > len)
		end = len;
	sb = malloc(sizeof(char) * (end + 1));
	if (!sb)
		return (0);
	if (end == 0)
		sb[end] = '\0';
	else
		ft_strlcpy(sb, s + start, end + 1);
	return (sb);
}

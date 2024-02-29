/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:19:21 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 07:20:03 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

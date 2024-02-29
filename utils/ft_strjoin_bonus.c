/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:31:18 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 10:31:22 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_strjoin(char *s1, char *s2, int free_s)
{
	char	*ptr;
	size_t	y;
	size_t	x;

	if (!s1 && !s2)
		return (ft_calloc(1, sizeof(char)));
	if (!s1 && s2)
		ptr = malloc((ft_strlen(s2) + 1) * sizeof(char));
	else if (s1 && !s2)
		ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	else
		ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x])
		ptr[y++] = s1[x++];
	x = 0;
	while (s2 && s2[x])
		ptr[y++] = s2[x++];
	ptr[y] = '\0';
	if (free_s == 1)
		ft_free(s1, s2);
	return (ptr);
}

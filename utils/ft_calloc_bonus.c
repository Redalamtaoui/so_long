/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:17:25 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 07:17:30 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	totale;
	char	*ptr;

	ptr = NULL;
	if (size > 0 && nitems > 0)
	{
		totale = nitems * size;
		if (totale / nitems != size)
			return (NULL);
		ptr = malloc(totale);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, totale);
	}
	else if (size == 0 || nitems == 0)
	{
		ptr = malloc(1);
		ptr[0] = 0;
		return ((void *)ptr);
	}
	return ((void *)ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:13:18 by rlamtaou          #+#    #+#             */
/*   Updated: 2023/11/17 15:50:37 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_size(long n)
{
	size_t	sum;

	sum = 0;
	if (n <= 0)
	{
		sum++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		sum++;
	}
	return (sum);
}

static void	ft_sign(char *str, long *nb)
{
	str[0] = '-';
	*nb = *nb * -1;
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	nb;

	nb = n;
	size = ft_size(nb);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
		ft_sign(str, &nb);
	while (nb > 0)
	{
		str[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

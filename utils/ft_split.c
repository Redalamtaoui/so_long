/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:10:58 by rlamtaou          #+#    #+#             */
/*   Updated: 2023/11/24 01:28:58 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_countword(char *s1, char c)
{
	size_t	sum;

	sum = 0;
	while (*s1)
	{
		while (*s1 == c && *s1 != '\0')
			s1++;
		if (*s1 != c && *s1 != '\0')
			sum++;
		while (*s1 != c && *s1 != '\0')
			s1++;
	}
	return (sum);
}

static char	*ft_initil(char *s, char c)
{
	size_t	x;
	char	*ptr;

	x = 0;
	while (s[x] != c && s[x] != '\0')
		x++;
	ptr = malloc((x + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	x = 0;
	while (s[x] != c && s[x] != '\0')
	{
		ptr[x] = s[x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

static char	**ft_free_all(char **ptr, size_t end)
{
	size_t	start;

	start = 0;
	while (start < end)
	{
		free(ptr[start]);
		ptr[start] = NULL;
		start++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	**ft_split2(char **ptr, char *s, char c)
{
	size_t	x;

	x = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			ptr[x] = ft_initil((char *)s, c);
			if (ptr[x++] == NULL)
				return (ft_free_all(ptr, x));
		}
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	ptr[x] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	total;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	total = ft_countword((char *)s, c);
	ptr = malloc(((total + 1) * sizeof(char *)));
	if (!ptr)
		return (NULL);
	ptr = ft_split2(ptr, (char *)s, c);
	return (ptr);
}

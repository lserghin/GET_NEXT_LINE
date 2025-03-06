/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:57:53 by lserghin          #+#    #+#             */
/*   Updated: 2024/11/26 15:56:19 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	char	*variant_s;

	if (!s)
		return (0);
	variant_s = (char *)s;
	while (*variant_s)
		variant_s++;
	return ((size_t)(variant_s - s));
}

char	*ft_strchr(char *s, int c)
{
	char	*variant_s;

	if (!s)
		return (NULL);
	variant_s = (char *)s;
	while (*variant_s)
	{
		if (*variant_s == (char)c)
			return (variant_s);
		variant_s++;
	}
	if (*variant_s == (char)c)
		return (variant_s);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	size_t	slen;
	char	*str;
	char	*origin;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	origin = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (origin);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	size;

	if (!src)
		return (0);
	srclen = ft_strlen(src);
	size = dstsize - 1;
	if (dstsize == 0)
		return (srclen);
	while (*src && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (free(s1), NULL);
	}
	if (!s2)
		return (free(s1), NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (free(s1), NULL);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcpy(str + s1len, s2, s2len + 1);
	return (free(s1), str);
}

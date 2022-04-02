/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:12:31 by cperegri          #+#    #+#             */
/*   Updated: 2022/01/06 15:26:33 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_len(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*str_chr(const char *s, int c)
{
	while (*s != (char)c)
	{		
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

void	str_lcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize > i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	return ;
}

void	str_lcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = str_len(dst);
	j = 0;
	if (i > dstsize)
		return ;
	while (src[j] && dstsize > i + j + 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize)
		dst[i + j] = 0;
	return ;
}

char	*str_join(const char *s1, const char *s2)
{
	char	*strjoin;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = str_len(s1);
	s2_len = str_len(s2);
	strjoin = malloc(s1_len + s2_len + 1);
	if (strjoin)
	{
		str_lcpy(strjoin, s1, s1_len + 1);
		str_lcat(strjoin, s2, s1_len + s2_len + 1);
	}
	return (strjoin);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:11:31 by cperegri          #+#    #+#             */
/*   Updated: 2022/01/06 15:25:23 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#if BUFFER_SIZE <= 0

char	*get_next_line(int fd)
{
	(void)fd;
	return (NULL);
}
#else

char	*str_sub(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		s_len;

	if (!s)
		return (NULL);
	s_len = str_len(s);
	if (start > s_len)
		len = 0;
	s += start;
	start = s_len;
	if (start < len)
		len = start;
	substr = malloc(sizeof(*s) * (len + 1));
	if (substr)
		str_lcpy(substr, s, len + 1);
	return (substr);
}

static char	*get_line(char **tmp, char **line)
{
	int		i;
	char	*nl;

	i = 0;
	nl = 0;
	while (*(*tmp + i) != '\n' && *(*tmp + i))
		i++;
	if (*(*tmp + i) == '\n')
	{
		*line = str_sub(*tmp, 0, i + 1);
		nl = str_sub(*tmp, i + 1, str_len(*tmp) - i - 1);
	}
	else
		*line = str_sub(*tmp, 0, str_len(*tmp));
	free(*tmp);
	*tmp = 0;
	return (nl);
}

static int	get_read(int fd, char **line, char *buffer, char **tmp)
{
	int		read_size;
	char	*buf;

	read_size = 1;
	while (read_size && !str_chr(*tmp, '\n'))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		buf = *tmp;
		*tmp = str_join(buf, buffer);
		free (buf);
	}
	buffer = 0;
	*tmp = get_line(tmp, line);
	return (read_size);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*tmp;
	int			read_size;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!tmp)
	{	
		tmp = malloc(1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	read_size = get_read(fd, &line, buffer, &tmp);
	if (!read_size && !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

#endif
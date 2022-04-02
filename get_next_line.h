/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:12:32 by cperegri          #+#    #+#             */
/*   Updated: 2022/01/06 15:25:38 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		str_len(const char *s);
char	*str_chr(const char *s, int c);
char	*str_sub(char const *s, unsigned int start, size_t len);
void	str_lcpy(char *dst, const char *src, size_t dstsize);
void	str_lcat(char *dst, const char *src, size_t dstsize);
char	*str_join(char const *s1, char const *s2);

#endif
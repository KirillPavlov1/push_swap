/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:24:48 by cvirgin           #+#    #+#             */
/*   Updated: 2021/08/03 19:35:19 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1000

int	free_mem(char **str, char *a, char *buf)
{
	if (a)
	{
		free(buf);
		return (1);
	}
	if (buf)
		return (0);
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (0);
}

char	*install_mem(int n)
{
	char	*str;

	str = (char *)malloc(n * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

int	checking(char **line, char *old, char **a)
{
	char	*s;

	*a = NULL;
	if (old)
	{
		*a = ft_strchr2(old, '\n');
		if ((*a))
		{
			**a = '\0';
			*line = ft_strdup(old);
			ft_strcpy(old, ++*a);
		}
		else
		{
			*line = install_mem(1);
			s = *line;
			*line = ft_strjoin(*line, old);
			free(s);
			return (0);
		}
	}
	else
		*line = install_mem(1);
	return (1);
}

int	gnl_join(char *buf, char **line, char **a, char **old)
{
	char	*c;

	*a = ft_strchr2(buf, '\n');
	if (*a)
	{
		**a = '\0';
		*old = ft_strdup(++*a);
	}
	c = *line;
	*line = ft_strjoin(*line, buf);
	free_mem(&c, NULL, NULL);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	char		*a;
	static char *old;
	int			i;
	int			k;

	i = 0;
	k = checking(line, old, &a);
	buf = install_mem(BUFFER_SIZE + 1);
	if (read(fd, old, 0) == -1 || k == -1)
		return (-1);
	if (free_mem(NULL, a, buf))
		return (1);
	if (!k)
		free_mem(&old, NULL, NULL);
	while (!a && (i = read(fd, buf, BUFFER_SIZE)))
	{
		buf[i] = '\0';
		gnl_join(buf, line, &a, &old);
	}
	free_mem(&buf, NULL, NULL);
	return (i ? 1 : 0);
}

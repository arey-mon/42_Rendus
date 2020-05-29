/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <apreymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:23:56 by apreymon          #+#    #+#             */
/*   Updated: 2019/12/10 21:40:38 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>

int				create_line(char **stock, char **line, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	if ((*stock)[i] == '\n')
	{
		*line = ft_substr(*stock, 0, i);
		tmp = ft_strdup(&((*stock)[i + 1]));
		free (*stock);
		*stock = tmp;
	}
	else
	{
	*line = ft_strdup(*stock);
	if ((*stock)[i] == '\0')
	{
		ret = 0;
		return (0);
	}
		free (*stock);
		*stock = NULL;
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*rest[1000];
	char			*ret_string;
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	i = 0;
	if ((fd < 0) || (line == NULL))
		return (-1);
	*line = ft_strdup("");
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (rest[fd] == NULL)
			rest[fd] = ft_strdup(buf);
		else
		{
			ret_string = ft_strjoin(rest[fd], buf);
			free (rest[fd]);
			rest[fd] = ret_string;
		}
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	if (ret == 0 && rest[fd] == '\0')
		return (0);
	return (check_ret(ret, fd, rest, line));
}

int				check_ret(int ret, int fd, char **stock, char **line)
{
	if (ret < 0)
		return (-1);
	else
		return (create_line(&stock[fd], line, ret));
}

size_t			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc(sizeof(char *) * (ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] && s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

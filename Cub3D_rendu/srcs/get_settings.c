/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:10:31 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/05 16:28:51 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/cub3d.h"
#include "../libft/libft.h"

int			in_set(char c, char *charset)
{
	while (*charset)
		if (c == *(charset++))
			return (1);
	return (0);
}

static int	get_map(t_settings *set, int fd, char *str)
{
	char	*s2;

	s2 = NULL;
	str = ft_strjoin_free_dest(str, "\n");
	while (get_next_line(fd, &s2))
	{
		if (!ft_strchr(s2, '1'))
		{
			free(str);
			free(s2);
			return (INV_SYN);
		}
		s2 = ft_strjoin_free_dest(s2, "\n");
		str = ft_strjoin_free(str, s2);
	}
	if (*s2 != '\n')
		str = ft_strjoin_free(str, s2);
	set->map = ft_split(str, '\n');
	free(str);
	return (0);
}

static char	*fill_fields(t_settings *set, int fd, char *str)
{
	while (get_next_line(fd, &str))
	{
		if (ft_strchr(str, '1') && !ft_isalpha(*str))
			return (str);
		if (*str == 'R')
			get_res(&set->res_x, &set->res_y, str);
		else if (*str == 'N')
			set->t_n = get_text(str + 2);
		else if (*str == 'E')
			set->t_e = get_text(str + 2);
		else if (*str == 'S' && *(str + 1) == 'O')
			set->t_s = get_text(str + 2);
		else if (*str == 'W')
			set->t_w = get_text(str + 2);
		else if (*str == 'S')
			set->t_sp = get_text(str + 1);
		else if (*str == 'F')
			get_color(set->rgb_f, str);
		else if (*str == 'C')
			get_color(set->rgb_c, str);
		free(str);
	}
	return (NULL);
}

int			get_settings(t_game *g, t_settings *set, int fd)
{
	char	*str;
	int		ret;

	ret = 0;
	str = NULL;
	if (fd > 0)
	{
		init_rgb(set);
		str = fill_fields(set, fd, str);
		ret = get_map(set, fd, str);
		close(fd);
	}
	if (fd <= 0 || ret == 13)
	{
		fd <= 0 ? clean_exit(4, g) : clean_exit(13, g);
		return (1);
	}
	return (0);
}

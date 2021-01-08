/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:48 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/20 18:35:29 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}

int		ft_strchr_int(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_stronechar(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

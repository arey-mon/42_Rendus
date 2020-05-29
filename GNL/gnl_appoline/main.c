/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 21:40:47 by tharchen          #+#    #+#             */
/*   Updated: 2019/12/10 22:01:28 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	if (ac < 2)
		fd = 0;
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	line = NULL;
	int l = 0;
	int q = 10;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// if (!	q)
		// 	fd = 1287934687;
		q--;
		printf("%-3d | %d | \"%s\"\n", ++l, ret, line);
		if (line)
			{free(line); line = NULL;}
	}
	printf("%d | \"%s\"\n", ret, line);
	if (line)
		{free(line); line = NULL;}
	print_mem__(PRINT_ALL);
	return (0);
}
//LAST
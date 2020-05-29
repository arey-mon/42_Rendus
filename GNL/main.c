/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:48:09 by apreymon          #+#    #+#             */
/*   Updated: 2019/12/10 22:12:38 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int   main()
{
	char	*line;
	int		fd1;
	int		fd2;
//	char	buf[BUFFER_SIZE + 1]; // a la compilation
	int		ret;

//	fd1 = open(av[1], O_RDONLY); //getting fd = -1 with random args
//	fd2 = open(av[2], O_RDONLY);
	fd1 = open("testfile", O_RDONLY);
	fd2 = open("tesfile2", O_RDONLY);
	while ((ret = get_next_line(fd1, &line)))
	{
		printf("'%s' [%d]\n", line, ret);
	free(line);
	}
		printf("'%s' [%d]\n", line, ret);
	free(line);
	while ((ret = get_next_line(fd2, &line)))
	{
		printf("'%s' [%d]\n", line, ret);
	free(line);
	}
		printf("'%s' [%d]\n", line, ret);
	free(line);
	close(fd1);
	close(fd2);
//	//	while ((ret = get_next_line(fd2, &line)))
//		printf("%s\n", line);
/*	get_next_line(fd1, &line)
	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
//	*/
	system("leaks a.out");
	return (0);
}


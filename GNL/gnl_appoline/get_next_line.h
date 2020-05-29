/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <apreymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:55:12 by apreymon          #+#    #+#             */
/*   Updated: 2019/12/10 22:00:03 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRY_MALLOC_H
# define TRY_MALLOC_H

#include "color_shell.h"

#ifndef __SIZE_MALLOC_DEBUG
# define __SIZE_MALLOC_DEBUG	1000000
#endif
# define PRINT_ALL	0
# define PRINT_OK	1
# define PRINT_KO	2
# define _FL_ (char *)__FUNCTION__, (int)__LINE__
# define MEM_USED_BY_DEBUG (size_t)(sizeof(t_debug_malloc) * __SIZE_MALLOC_DEBUG) + sizeof(t_debug_malloc) + (sizeof(size_t) * 2)
# define GDM g_debug_malloc[i]
typedef struct			s_debug_malloc
{
	void				*mem;
	int					size;
	int					real_size;
	char				*f_malloc;
	int					l_malloc;
	char				*f_free;
	int					l_free;
	int					nb_free;
}						t_debug_malloc;
extern t_debug_malloc	g_debug_malloc[__SIZE_MALLOC_DEBUG];
extern size_t			g_i_malloc;
extern int				__test;
void					print_mem__(int opt);
void					*try_malloc(size_t size, char *f, int l);
void					try_free_(void **p, char *f, int l);
void					try_free_all(char *f, int l);
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>

int				get_next_line(int fd, char **line);
int				create_line(char **stock, char **line, int ret);
int				check_ret(int ret, int fd, char **stock, char **line);
size_t			ft_strlen(const char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *str, int c);
#endif


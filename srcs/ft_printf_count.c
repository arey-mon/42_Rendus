// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_printf_count.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
// /*   Updated: 2020/04/24 12:17:34 by apolliner        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
// #include "ft_printf.h"
// #include <stdio.h>
//
// // count of x || X when P < 0
// int		ft_get_count_neg(char *arg, t_parsing *parsing)
// { //printf("____ ENTERED FT_COUNT_NEG ____\n");
// (void)*arg;
// 	int size;
//
// 	size = ft_strlen(parsing->aff);
// 	// if ((*arg == 'i' || *arg == 'd') && parsing->prec > size)
// 	// { printf("\ncoming in\n");
// 	// 	parsing->arg_count -= 1;
// 	// }
// 		return (1);
// }
//
// int		ft_get_count(char *arg, t_parsing *parsing, int flags)
// { //printf("____ ENTERED GET_COUNT ___\n");
// 	flags = 0;
// 	(void)*arg;
// 	if (parsing->neg == 1)
// 		ft_get_count_neg(arg, parsing);
// 	else
// 		ft_get_count2(arg, parsing, flags);
// 	if (parsing->arg_count < 0)
// 		parsing->arg_count = 0;
// //printf(">>>>out of get_count, count is [%d]\n", parsing->arg_count);
// 		return (1);
// }
//
// int		ft_get_count2(char *arg, t_parsing *parsing, int flags)
// { //printf("out of get_count2, count is [%d]\n", parsing->arg_count);
// 	(void)*arg;
// 	(void)*parsing;
// 	flags = 0;
// // 	if (*parsing->aff == '0' && parsing->prec == 0 && *arg != 'p' &&
// // 			*arg != 'i')
// // 		parsing->arg_count += 1;
// // 	if (*parsing->aff == '0' && parsing->prec == 0 && (*arg == 'u' || *arg ==
// // 				'd' || *arg == 'x' || *arg == 'X') && parsing->width == 0)
// // 		parsing->arg_count -= 1;
// // 	else if (*arg == 'i' && parsing->prec == 0 && parsing->width > 0)
// // 		parsing->arg_count += 1;
// // 	if (*arg == 'c' && !ft_strlen(parsing->aff) && parsing->width == 0)
// // 		parsing->arg_count += 1;
// // 	else if (*arg == 'c' && parsing->width != 0)
// // 	{ //printf(">>>get_count3, count is [%d]\n", parsing->arg_count);
// // 		parsing->arg_count += parsing->width - ft_strlen(parsing->aff);
// // printf(">>>get_count3, count is [%d]\n", parsing->arg_count);
// // 	}
// 	// if (*arg == 'p')
// 	// {
// 	// 	if (parsing->neg == 1 && parsing->prec == -1 && parsing->width >=
// 	// 			(ft_strlen(parsing->aff)))
// 	// 		parsing->arg_count += (parsing->width -
// 	// 				ft_strlen(parsing->aff) - 2);
// 	// }
// 	 if (*arg != 'c' && *arg != 's')
// 		ft_get_count3(arg, parsing, flags);
// 			//printf(">>>>out of get_count2, count is [%d]\n", parsing->arg_count);
// 	return (1);
// }
//
// void	ft_get_count3(char *arg, t_parsing *parsing, int flags)
// { //printf("into get_count3, count is [%d]\n", parsing->arg_count);
// 	(void)*arg;
// 	flags += parsing->width >= parsing->prec ? parsing->width : parsing->prec;
// 	// if (ft_strlen(parsing->aff) < flags)
// 	// { //printf(">>>>>>>\n");
// 	// 		parsing->arg_count += (flags - ft_strlen(parsing->aff));
// 	// }
// 	// if ((*arg == 'X' || *arg == 'x' || *arg == 'i') && parsing->neg == 1 &&
// 	// 		parsing->prec > ft_strlen(parsing->aff))
// 	// { //printf(">>>>>>>\n");
// 	// 	parsing->arg_count -= 1;
// 	// 	if (*arg == 'i' && *parsing->aff == '-' && parsing->prec >=
// 	// 			parsing->width)
// 	// 		parsing->arg_count += 1;
// 	// }
// 	// else if ((*arg == 'i' || (*arg == 'd' && parsing->neg == 0)) &&
// 	// 		parsing->prec > ft_strlen(parsing->aff) && *parsing->aff == '-')
// 	// { //printf(">>>>>>>\n");
// 	// 	if (parsing->width != 0 && parsing->width <= parsing->prec &&
// 	// 			parsing->zero != 1)
// 	// 		parsing->arg_count += 1;
// 	// }
// 	// else if (*arg == 'd' && parsing->neg == 1 && parsing->width > parsing->prec
// 	// 		&& parsing->prec != -1)
// 	// 	if (parsing->prec >= ft_strlen(parsing->aff))
// 	// 		{ //printf(">>>>>>>\n");
// 	// 			parsing->arg_count -= 1;
// 	// 		}
// 	//printf(">>>>out of get_count3, count is [%d]\n", parsing->arg_count);
// }

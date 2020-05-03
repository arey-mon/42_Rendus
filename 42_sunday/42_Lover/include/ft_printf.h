/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/29 18:04:19 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_parsing
{
	int				width;
	int				prec;
	int				neg;
	int				zero;
	int				arg_pos;
	int				arg_count;
	int				cnull;
	char			*aff;
	int				zero_flags;
	int				space_flags;
}					t_parsing;

int					ft_is_printf_format(const char *format);
int					ft_is_digit(int d);
int					ft_is_flag(const char *format);
int					ft_strlen(char *s);
void				ft_putchar_fd(const char c, int fd);
int					ft_putstr_fd(const char *str, int fd);
int					is_pointer_adress(va_list av);
char				*ft_strdup(const char *s1);
char				*ft_aff_c(int d);
char				*ft_aff_c(int d);
int					ft_printf(const char *format, ...);
int					ft_loop(char *arg, va_list *av, t_parsing parsing, int len);
int					ft_is_printf_format(const char *format);
void				ft_init_parsing(t_parsing *parsing);
int					ft_parsing(char *arg, va_list *va, t_parsing *parsing);
int					ft_get_flags(char *arg, t_parsing *parsing);
void				ft_format_type(char type, va_list *av, t_parsing *parsing);
void				ft_flags_count(char *arg, t_parsing *parsing,
		int flags_size);
void				ft_flags_aff(char *arg, t_parsing *parsing, char c, char
		*tmp);
void				ft_flags_aff2(char *arg, t_parsing *parsing);
void				ft_flags_aff3(char *arg, t_parsing *parsing, char c,
		char *tmp);
void				ft_flags_aff_prepa(char *arg, t_parsing *parsing, char c);
int					ft_arg_count(char *arg, va_list *av, t_parsing *parsing);
int					ft_width(char *arg, va_list *av, t_parsing *parsing);
int					ft_precision(char *arg, va_list *av, t_parsing *parsing);
void				ft_strings(char *arg, t_parsing *parsing, char *tmp);
void				ft_string_precision(char *arg, t_parsing *parsing, char c,
		char *tmp);
void				ft_string_precision2(t_parsing *parsing, char c, char *tmp);
void				ft_string_exceptions(char *arg, t_parsing *parsing, char c,
		char *tmp);
void				ft_string_exceptions_neg(t_parsing *parsing, char c, char
		*tmp);
void				ft_neg_value(char *arg, t_parsing *parsing);
void				ft_double_neg(char *arg, t_parsing *parsing);
void				ft_neg_value_w(t_parsing *parsing);
void				ft_neg_value_w2(t_parsing *parsing);
void				ft_neg_value_p(char *arg, t_parsing *parsing);
void				ft_neg_prepare(char *arg, t_parsing *parsing);
void				ft_neg_prepare2(char *arg, t_parsing *parsing);
void				ft_neg_prepare3(t_parsing *parsing, int aff_count);
void				ft_pointers_deal(char *arg, t_parsing *parsing);
char				*ft_putnbr_base_ulong(unsigned long nbr, char *base);
char				*ft_putnbr_base_ulong2(unsigned long nbr, char *base,
		int size_base);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/02 17:16:55 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_parsing(t_parsing *parsing)
{
	parsing->prec = -1;
	parsing->width = 0;
	parsing->aff = NULL;
	parsing->neg = 0;
	parsing->zero = 0;
	parsing->zero_flags = 0;
	parsing->space_flags = 0;
	parsing->arg_pos = 0;
	parsing->cnull = -1;
}

void		ft_format_type(char type, va_list *av, t_parsing *parsing)
{
	if (type == '%')
		parsing->aff = ft_aff_c('%');
	else if (type == 'c')
		parsing->aff = ft_aff_c(va_arg(*av, int));
	else if (type == 's')
		parsing->aff = ft_strdup(va_arg(*av, char*));
	else if (type == 'd' || type == 'i')
		parsing->aff = ft_itoa(va_arg(*av, int));
	else if (type == 'u')
		parsing->aff = ft_putnbr_base_ulong(va_arg(*av, unsigned),
				"0123456789");
	else if (type == 'x')
		parsing->aff =
			ft_putnbr_base_ulong(va_arg(*av, unsigned), "0123456789abcdef");
	else if (type == 'X')
		parsing->aff =
			ft_putnbr_base_ulong(va_arg(*av, unsigned), "0123456789ABCDEF");
	else if (type == 'p')
		parsing->aff = ft_putnbr_base_ulong(va_arg(*av, unsigned long),
				"0123456789abcdef");
}

int			ft_arg_count(char *arg, va_list *av, t_parsing *parsing)
{
	int		i;
	int		flags_size;
	char	c;
	char	*tmp;

	c = ' ';
	flags_size = 0;
	tmp = NULL;
	i = 0;
	i += ft_get_flags(&arg[i], parsing);
	i += ft_width(&arg[i], av, parsing);
	i += ft_precision(&arg[i], av, parsing);
	if (ft_is_printf_format(&arg[i]))
	{
		ft_format_type(arg[i], av, parsing);
		ft_flags_count(&arg[i], parsing, flags_size);
		ft_flags_aff(&arg[i], parsing, c, tmp);
		return (++i);
	}
	return (0);
}

int			ft_loop(char *arg, va_list *av, t_parsing parsing, int len)
{
	len = 0;
	while (*arg)
	{
		ft_init_parsing(&parsing);
		if (*arg == '%')
		{
			arg++;
			arg += ft_arg_count(arg, av, &parsing);
			if (parsing.aff)
				len += ft_putstr_fd(parsing.aff, 1);
			if (parsing.cnull == 0)
				ft_putchar_fd(parsing.cnull, 1);
		}
		if (!parsing.aff && *arg && *arg != '%')
		{
			ft_putchar_fd(*arg, 1);
			len++;
			arg++;
		}
		free(parsing.aff);
	}
	len += parsing.arg_count;
	return (len);
}

int			ft_printf(const char *format, ...)
{
	char		*arg;
	va_list		av;
	int			count;
	int			len;
	t_parsing	parsing;

	len = 0;
	parsing.arg_count = 0;
	va_start(av, format);
	arg = (char *)format;
	count = ft_loop(arg, &av, parsing, len);
	va_end(av);
	return (count);
}

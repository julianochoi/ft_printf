/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:03:17 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/27 00:18:57 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		conversion(t_flags *flags, char *f_cpy, int *i, va_list ap)
{
	while (!(is_specifier(f_cpy[*i])) && f_cpy[*i])
	{
		if ((ft_isdigit(f_cpy[*i]) && f_cpy[*i] != '0') && flags->dot == 0)
		{
			flags->field_width = ft_atoi((const char *)(f_cpy + *i));
			(*i) += count_digits(flags->field_width);
		}
		else if (ft_isdigit(f_cpy[*i]) && flags->dot == 1)
		{
			flags->precision = ft_atoi((const char *)(f_cpy + *i));
			(*i) += count_digits(flags->precision);
			flags->precision_read = 1;
		}
		else
			flag_handler(flags, f_cpy[(*i)++], ap);
	}
	if (is_specifier(f_cpy[*i]))
		flags->type = f_cpy[(*i)++];
}

static void		conversion_handlers(t_flags *flags, va_list ap)
{
	if (flags->type == 'd' || flags->type == 'i')
		int_handler(flags, ap);
	if (flags->type == 'c')
		chr_handler(flags, ap);
	if (flags->type == 's')
		str_handler(flags, ap);
	if (flags->type == 'x' || flags->type == 'X')
		hex_handler(flags, ap);
	if (flags->type == 'u')
		u_handler(flags, ap);
	if (flags->type == 'p')
		ptr_handler(flags, ap);
	if (flags->type == '%')
		percent_handler(flags);
}

static void		copy_ordinary(t_flags *flags, char *f_cpy, int *i, int *pos)
{
	char *temp;
	char *substr;

	temp = ft_strdup(flags->buffer);
	substr = ft_substr(f_cpy, *pos, ((*i)++) - *pos);
	free_and_null(flags->buffer);
	if (!(flags->buffer = ft_strjoin(temp, substr)))
		return ;
	free_and_null(substr);
	free_and_null(temp);
}

static void		format_parser(t_flags *flags, char *f_cpy, va_list ap)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (f_cpy[i] != '\0')
	{
		if (f_cpy[i] == '%' && f_cpy[i + 1] != '\0')
		{
			reset_flags(flags);
			copy_ordinary(flags, f_cpy, &i, &pos);
			conversion(flags, f_cpy, &i, ap);
			pos = i;
			conversion_handlers(flags, ap);
		}
		else
			i++;
	}
	copy_ordinary(flags, f_cpy, &i, &pos);
}

int				ft_printf(const char *f_str, ...)
{
	va_list	ap;
	char	*f_cpy;
	t_flags	flags;

	if (!f_str || !f_str[0])
		return (0);
	flags.return_value = 0;
	flags.buffer = ft_strdup("");
	reset_flags(&flags);
	f_cpy = ft_strdup(f_str);
	va_start(ap, f_str);
	format_parser(&flags, f_cpy, ap);
	flags.return_value += ft_strlen(flags.buffer);
	write(1, flags.buffer, ft_strlen(flags.buffer));
	va_end(ap);
	free_and_null(f_cpy);
	free_and_null(flags.buffer);
	return (flags.return_value);
}

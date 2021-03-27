/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:26:51 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/19 17:52:07 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		flag_check_char(t_flags *flags)
{
	if (flags->zero && !flags->minus)
		flags->padding = '0';
	else
		flags->padding = 32;
	if (flags->dot && !flags->precision_read)
		flags->precision = 0;
}

static void	chr_zero_handler(t_flags *flags, char **conversion)
{
	int n;

	flags->return_value += ft_strlen(flags->buffer);
	write(1, flags->buffer, ft_strlen(flags->buffer));
	free_and_null(flags->buffer);
	free_and_null(*conversion);
	flags->buffer = ft_strdup("");
	n = max_int(flags->field_width, 1);
	*conversion = ft_calloc(n + 1, sizeof(char));
	ft_memset(*conversion, flags->padding, n);
	if (flags->minus)
		(*conversion)[0] = 0;
	else
		(*conversion)[n - 1] = 0;
	write(1, *conversion, n);
	free_and_null(*conversion);
	flags->return_value += n;
}

void		chr_handler(t_flags *flags, va_list ap)
{
	char	*conversion;

	flag_check_char(flags);
	conversion = ft_calloc(2, sizeof(char));
	if (!(conversion[0] = (unsigned char)va_arg(ap, int)))
		chr_zero_handler(flags, &conversion);
	else
	{
		if (flags->field_width > 1)
			add_padding(flags, &conversion, 1);
		add_to_buffer(flags, &conversion);
	}
}

void		str_handler(t_flags *flags, va_list ap)
{
	const char	*str;
	char		*conversion;
	int			len;
	int			condition;

	flag_check_char(flags);
	if (!(str = va_arg(ap, const char *)))
	{
		condition = (flags->precision >= 0 ? min_int(flags->precision, 6) : 6);
		conversion = ft_substr("(null)", 0, condition);
	}
	else
	{
		if (flags->precision >= 0)
			len = min_int((int)ft_strlen(str), flags->precision);
		else
			len = ft_strlen(str);
		conversion = ft_calloc(len + 1, sizeof(char));
		ft_memcpy(conversion, str, len);
	}
	if ((int)ft_strlen(conversion) < flags->field_width)
		add_padding(flags, &conversion, 1);
	add_to_buffer(flags, &conversion);
}

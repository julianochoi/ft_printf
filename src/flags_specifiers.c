/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:03:36 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/18 18:28:05 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	is_valid_flag(char c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*');
}

bool	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%');
}

void	flag_handler(t_flags *flags, char c, va_list ap)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '.')
		flags->dot = 1;
	else if (c == '*' && flags->dot == 0)
	{
		flags->star = 1;
		if ((flags->field_width = va_arg(ap, int)) < 0)
		{
			flags->minus = 1;
			flags->field_width *= -1;
		}
	}
	else if (c == '*' && flags->dot == 1)
	{
		flags->star = 1;
		flags->precision = va_arg(ap, int);
		if (flags->precision >= 0)
			flags->precision_read = 1;
		else
			flags->dot = 0;
	}
}

void	reset_flags(t_flags *flags)
{
	flags->type = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->field_width = 0;
	flags->precision = -1;
	flags->precision_read = 0;
	flags->padding = 32;
}

void	flag_check_ints(t_flags *flags)
{
	if (flags->minus || flags->precision_read)
		flags->zero = 0;
	else if (flags->zero)
		flags->padding = '0';
	if (flags->dot && !flags->precision_read)
		flags->precision = 0;
}

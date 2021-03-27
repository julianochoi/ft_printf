/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:26:51 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/17 22:21:08 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u_handler(t_flags *flags, va_list ap)
{
	ssize_t	num;
	char	*conversion;

	flag_check_ints(flags);
	num = va_arg(ap, unsigned int);
	if (!num && !flags->precision)
		conversion = ft_strdup("");
	else
		conversion = ft_itoa_base(num, "0123456789");
	if (count_digits(num) <= flags->precision)
		add_zeroes(flags, &conversion, 1);
	if ((int)ft_strlen(conversion) < flags->field_width)
		add_padding(flags, &conversion, 1);
	add_to_buffer(flags, &conversion);
}

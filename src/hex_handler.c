/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:26:51 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/18 22:30:55 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hex_handler(t_flags *flags, va_list ap)
{
	ssize_t	num;
	char	*conversion;
	char	hex_base[17];

	flag_check_ints(flags);
	num = va_arg(ap, unsigned int);
	if (flags->type == 'X')
		ft_memcpy(hex_base, "0123456789ABCDEF", 16);
	else
		ft_memcpy(hex_base, "0123456789abcdef", 16);
	hex_base[16] = 0;
	if (!num && !flags->precision)
		conversion = ft_strdup("");
	else
		conversion = ft_itoa_base(num, hex_base);
	if ((int)ft_strlen(conversion) < flags->precision)
		add_zeroes(flags, &conversion, 1);
	if ((int)ft_strlen(conversion) < flags->field_width)
		add_padding(flags, &conversion, 1);
	add_to_buffer(flags, &conversion);
}

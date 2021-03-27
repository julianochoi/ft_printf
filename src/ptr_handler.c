/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:26:51 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/27 00:18:37 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_ptr_prefix(char **conversion)
{
	char *temp;

	temp = ft_calloc(ft_strlen(*conversion) + 3, sizeof(char));
	ft_memcpy(temp, "0x", 2);
	ft_memcpy(temp + 2, *conversion, ft_strlen(*conversion));
	free_and_null(*conversion);
	*conversion = ft_strdup(temp);
	free_and_null(temp);
}

void		ptr_handler(t_flags *flags, va_list ap)
{
	ssize_t	num;
	char	*conversion;
	char	hex_base[17];

	flag_check_ints(flags);
	num = (ssize_t)va_arg(ap, void *);
	ft_memcpy(hex_base, "0123456789abcdef", 16);
	hex_base[16] = 0;
	if (!num && !flags->precision)
		conversion = ft_strdup("");
	else
		conversion = ft_itoa_base(num, hex_base);
	if (count_digits(num) <= flags->precision)
		add_zeroes(flags, &conversion, 1);
	add_ptr_prefix(&conversion);
	if ((int)ft_strlen(conversion) < flags->field_width)
		add_padding(flags, &conversion, 1);
	if (conversion)
		add_to_buffer(flags, &conversion);
}

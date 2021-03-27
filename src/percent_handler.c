/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:21:37 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/27 00:18:33 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_handler(t_flags *flags)
{
	char		*conversion;

	flag_check_char(flags);
	conversion = ft_strdup("\%");
	if ((int)ft_strlen(conversion) < flags->field_width)
		add_padding(flags, &conversion, 1);
	add_to_buffer(flags, &conversion);
}

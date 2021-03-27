/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:31:50 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/27 00:18:48 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_digits(int num)
{
	int size;

	size = 0;
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return ((!size ? 1 : size));
}

void	add_zeroes(t_flags *flags, char **str, int sign)
{
	char	*padding;
	int		n;
	int		len;
	int		size;

	if ((n = flags->precision - ft_strlen(*str)) < 0)
		n = 0;
	len = (sign == -1 ? 2 : 1) + max_int(flags->precision, ft_strlen(*str));
	if (!(padding = ft_calloc(len, sizeof(char))))
		return ;
	size = (sign == -1 ? 1 : 0) + n;
	ft_memset(padding, '0', size);
	ft_memcpy(padding + size, *str, ft_strlen(*str));
	if (sign == -1)
		padding[0] = '-';
	free_and_null(*str);
	*str = ft_strdup(padding);
	free_and_null(padding);
}

void	add_padding(t_flags *flags, char **conversion, int sign)
{
	char	*padding;
	char	*temp;
	int		n;
	int		zero_condition;

	n = flags->field_width - ft_strlen(*conversion);
	zero_condition = ((sign == -1 && flags->zero) ? 1 : 0);
	if (!(padding = ft_calloc(n + zero_condition + 1, sizeof(char))))
		return ;
	ft_memset(padding, flags->padding, n + zero_condition);
	padding[n + zero_condition] = '\0';
	if (flags->zero)
	{
		temp = ft_strjoin(padding, *conversion + zero_condition);
		temp[0] = (sign == -1 ? '-' : '0');
	}
	if (flags->minus)
		temp = ft_strjoin(*conversion, padding);
	else if (!(flags->zero))
		temp = ft_strjoin(padding, *conversion);
	free_and_null(padding);
	free_and_null(*conversion);
	*conversion = ft_strdup(temp);
	free_and_null(temp);
}

void	add_to_buffer(t_flags *flags, char **conversion)
{
	char *temp;

	if (!(temp = ft_strjoin(flags->buffer, *conversion)))
		return ;
	if (flags->buffer)
		free_and_null(flags->buffer);
	if (*conversion)
		free_and_null(*conversion);
	flags->buffer = ft_strdup(temp);
	free_and_null(temp);
}

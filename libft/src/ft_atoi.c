/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:50:27 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/11 10:22:28 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == ' ')
	|| (c == '\f')
	|| (c == '\n')
	|| (c == '\r')
	|| (c == '\t')
	|| (c == '\v'));
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		num;
	int		pos;

	sign = 1;
	num = 0;
	pos = 0;
	while (str[pos] && ft_isspace(str[pos]))
		pos++;
	if (str[pos] && (str[pos] == '+' || str[pos] == '-'))
	{
		if (str[pos] == '-')
			sign = -1;
		pos++;
	}
	while (str[pos] && ft_isdigit(str[pos]))
	{
		num = (num * 10) + (str[pos] - '0');
		pos++;
	}
	return (num * sign);
}

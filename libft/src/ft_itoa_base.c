/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:25:43 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/16 17:32:30 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_base_nbr_size(size_t num, int radix)
{
	size_t size;

	size = 0;
	while (1)
	{
		num /= radix;
		size++;
		if (num == 0)
			break ;
	}
	return (size);
}

char			*ft_itoa_base(unsigned long n, char *base)
{
	size_t	num;
	size_t	radix;
	char	*array;
	size_t	size;

	num = n;
	radix = ft_strlen(base);
	size = itoa_base_nbr_size(num, radix);
	if (!(array = malloc(size + 1)))
		return (NULL);
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = base[num % radix];
		num /= radix;
		size--;
		if (num == 0)
			break ;
	}
	return (array);
}

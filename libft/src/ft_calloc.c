/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:57:34 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/11 10:23:04 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	mem_size;

	mem_size = nmemb * size;
	if (!(array = malloc(mem_size)))
		return (NULL);
	ft_memset(array, 0, mem_size);
	return (array);
}

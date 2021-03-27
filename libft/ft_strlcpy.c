/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:07:56 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/16 23:26:40 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;
	size_t src_len;

	if (!(dst) || !(src))
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while ((i < (size - 1)) && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

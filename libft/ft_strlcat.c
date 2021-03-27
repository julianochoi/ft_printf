/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:28:05 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/13 11:22:54 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const	char *src, size_t size)
{
	char	*dst_idx;
	char	*src_idx;
	size_t	dst_len;
	size_t	i;

	dst_idx = dst;
	src_idx = (char *)src;
	i = size;
	while (i-- != 0 && *dst_idx != '\0')
		dst_idx++;
	dst_len = dst_idx - dst;
	i = size - dst_len;
	if (i == 0)
		return (dst_len + ft_strlen(src_idx));
	while (*src_idx != '\0')
	{
		if (i > 1)
		{
			*dst_idx++ = *src_idx;
			i--;
		}
		src_idx++;
	}
	*dst_idx = '\0';
	return (dst_len + (src_idx - src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:38:44 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/16 23:12:03 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			step;
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	step = 1;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest > src)
	{
		step = -1;
		temp_dest = (unsigned char *)(dest + n - 1);
		temp_src = (unsigned char *)(src + n - 1);
	}
	i = 0;
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_dest += step;
		temp_src += step;
		i++;
	}
	return (dest);
}

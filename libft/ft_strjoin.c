/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:22:58 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/16 23:45:45 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*dest;

	if (!(s1) || !(s2))
		return (NULL);
	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	if (!(dest = ft_calloc(len_1 + len_2 + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(dest, (char *)s1, len_1);
	ft_memcpy(dest + len_1, (char *)s2, len_2);
	dest[len_1 + len_2] = '\0';
	return (dest);
}

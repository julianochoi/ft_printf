/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:33:24 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/18 00:17:25 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	len;
	size_t	idx;

	if (!s)
		return (NULL);
	idx = 0;
	len = ft_strlen(s);
	if (!(array = malloc(len + 1)))
		return (NULL);
	while (idx < len)
	{
		array[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	array[idx] = '\0';
	return (array);
}

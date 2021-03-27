/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:50:40 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/11 10:23:58 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_c;

	last_c = NULL;
	i = 0;
	while (1)
	{
		if (s[i] == c)
			last_c = (char *)s + i;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (last_c);
}

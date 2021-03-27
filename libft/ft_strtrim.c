/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:22:43 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/02/18 00:17:35 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_in_set(char c, const char *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static size_t	find_begin_end(const char *s1, char const *set,
								size_t len, char rev)
{
	size_t idx;
	size_t limit;

	limit = 0;
	while (limit < len)
	{
		idx = limit;
		if (rev)
			idx = len - limit - 1;
		if (!check_in_set(s1[idx], set))
			return (idx);
		limit++;
	}
	return (limit);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	begin;
	size_t	end;
	char	*str;

	if (!(s1) || !(set))
		return (NULL);
	len = ft_strlen(s1);
	begin = find_begin_end(s1, set, len, 0);
	end = find_begin_end(s1, set, len, 1);
	len = (begin > end) ? 0 : end - begin + 1;
	if (len <= 0)
		return (ft_strdup(""));
	if (!(str = malloc(len + 1)))
		return (NULL);
	ft_memcpy(str, (char *)s1 + begin, len);
	str[len] = '\0';
	return (str);
}

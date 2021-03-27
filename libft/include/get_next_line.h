/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:08:17 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/26 23:57:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	unsigned char	buffer[BUFFER_SIZE];
	unsigned char	*temp;
	size_t			read_size;
	size_t			temp_len;
	size_t			offset;
	int				active;
	int				end;
}					t_gnl;

int					get_next_line(int fd, char **line);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif

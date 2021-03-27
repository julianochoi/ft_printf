/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:46:20 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/01 23:51:24 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				ft_gnl_init_tracker(t_gnl *tracker, int flag, int ret)
{
	if (tracker->active != 1 || flag)
	{
		tracker->active = 1;
		tracker->end = 0;
		tracker->offset = BUFFER_SIZE;
		tracker->temp = NULL;
		tracker->temp_len = 0;
	}
	return (ret);
}

static unsigned char	*ft_gnl_filler(t_gnl *tracker, int flag)
{
	unsigned char	c;
	unsigned char	*str;

	c = tracker->buffer[tracker->offset];
	tracker->offset += 1;
	if (!(str = malloc((tracker->temp_len + 1) * sizeof(char))))
		return (NULL);
	if (tracker->temp != NULL)
	{
		ft_memcpy(str, tracker->temp, tracker->temp_len);
		free(tracker->temp);
	}
	if (c == '\n' || flag)
	{
		str[tracker->temp_len] = '\0';
		tracker->temp = NULL;
		tracker->temp_len = 0;
		return (str);
	}
	str[tracker->temp_len] = c;
	tracker->temp_len += 1;
	tracker->temp = str;
	return (NULL);
}

static int				ft_gnl_looper(t_gnl *tracker, char **line)
{
	unsigned char	*str;
	int				flag;

	while (tracker->offset + 1 < BUFFER_SIZE + 1)
	{
		flag = (tracker->offset >= tracker->read_size);
		str = ft_gnl_filler(tracker, flag);
		if (str != NULL)
		{
			if (flag)
				tracker->end = 1;
			*line = (char *)str;
			return (1);
		}
	}
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static t_gnl	trackers[RLIMIT_NOFILE];
	t_gnl			*tracker;

	if (fd < 0 || BUFFER_SIZE == 0 || fd > RLIMIT_NOFILE || line == NULL)
		return (-1);
	*line = NULL;
	tracker = (trackers + fd);
	ft_gnl_init_tracker(tracker, 0, 1);
	while (1)
	{
		if (tracker->offset == BUFFER_SIZE)
		{
			tracker->read_size = read(fd, tracker->buffer, BUFFER_SIZE);
			tracker->offset = 0;
		}
		if (tracker->read_size == (size_t)-1)
			return (-1);
		if (ft_gnl_looper(tracker, line))
		{
			if (tracker->read_size == 0 || tracker->end)
				return (ft_gnl_init_tracker(tracker, 1, 0));
			return (1);
		}
	}
}

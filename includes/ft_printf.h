/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:10:42 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/03/19 19:22:16 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	char	type;
	int		return_value;
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		field_width;
	int		precision;
	int		precision_read;
	char	padding;
	char	*buffer;
}				t_flags;

int				ft_printf(const char *f_str, ...);
void			add_zeroes(t_flags *flags, char **str, int sign);
void			add_padding(t_flags *flags, char **conversion, int sign);
void			add_to_buffer(t_flags *flags, char **conversion);
int				count_digits(int num);
void			flag_check_char(t_flags *flags);
void			flag_check_ints(t_flags *flags);
void			flag_handler(t_flags *flags, char c, va_list ap);
bool			is_valid_flag(char c);
bool			is_specifier(char c);
void			reset_flags(t_flags *flags);
void			chr_handler(t_flags *flags, va_list ap);
void			hex_handler(t_flags *flags, va_list ap);
void			int_handler(t_flags *flags, va_list ap);
void			percent_handler(t_flags *flags);
void			ptr_handler(t_flags *flags, va_list ap);
void			str_handler(t_flags *flags, va_list ap);
void			u_handler(t_flags *flags, va_list ap);

#endif

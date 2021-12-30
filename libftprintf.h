/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:36:57 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/29 20:20:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *s, ...);

char		*ft_read_char(va_list *args);
char		*ft_read_string(va_list *args);
char		*ft_read_pointer(va_list *args);
char		*ft_read_hex(va_list *args, char c);

void		ft_create_hex_string(char *output, char *input, int n,
				int leading_zeros);

#endif
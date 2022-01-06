/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:36:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 13:35:16 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

char	*ft_read_conversation(const char *s, va_list *args);
int		ft_write_char(char c);
int		ft_write_string(char *s);

char	*ft_read_char(va_list *args);
char	*ft_read_string(va_list *args);
char	*ft_read_pointer(va_list *args);
char	*ft_read_hex(va_list *args, char c);

void	ft_create_hex_string(char *output, char *input, int n,
				int leading_zeros);

#endif
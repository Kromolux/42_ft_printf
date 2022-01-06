/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:03:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 19:16:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int		left_aligned;
	int		right_aligned;
	int		leading_zeros;
	int		precision;
	int		leading_zeros_x;
	int		leading_whitespace;
	int		leading_plus;
}				t_flags;

int		ft_printf(const char *s, ...);

t_flags	*ft_read_flags(const char *s, int *i);
char	*ft_apply_flags(char *s, const char c, t_flags *flags);

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
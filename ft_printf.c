/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:39:00 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/07 16:48:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count_of_chars;
	char	*tmp_string;

	i = 0;
	count_of_chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			tmp_string = ft_read_conversation(&s[i], &args);
			if (tmp_string)
				count_of_chars += ft_write_string(tmp_string, s[i]);
		}
		else
			count_of_chars += ft_write_char((char) s[i]);
		i++;
	}
	va_end(args);
	return (count_of_chars);
}

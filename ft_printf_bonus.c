/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:57:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 19:15:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "libft/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count_of_chars;
	char	*tmp_string;
	t_flags	*flags;

	i = 0;
	count_of_chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			flags = ft_read_flags(s, &i);
			tmp_string = ft_read_conversation(&s[i], &args);
			tmp_string = ft_apply_flags(tmp_string, s[i], flags);
			if (tmp_string)
				count_of_chars += ft_write_string(tmp_string);
		}
		else
			count_of_chars += ft_write_char((char) s[i]);
		i++;
	}
	va_end(args);
	return (count_of_chars);
}

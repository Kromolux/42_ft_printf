/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:57:18 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/08 21:40:05 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "libft/libft.h"
#include <stdio.h>
static int	ft_printf_handling(const char *s, int *i, va_list *args);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count_of_chars;

	i = 0;
	count_of_chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			count_of_chars += ft_printf_handling(s, &i, &args);
		else
			count_of_chars += ft_write_char((char) s[i]);
		i++;
	}
	va_end(args);
	return (count_of_chars);
}

static int	ft_printf_handling(const char *s, int *i, va_list *args)
{
	t_flags	*flags;
	char	*tmp_string;
		
	(*i)++;
	//printf("\nbefore read_flags tmp_string = %s char = %c i = %i\n", tmp_string, s[i], i);
	flags = ft_read_flags(s, i);
	//tmp_string[0] = '\0';
	//printf("flags->right_aligned = %i\n", flags->right_aligned);
	//printf("\nbefore conversation tmp_string = %s char = %c i = %i\n", tmp_string, s[*i], *i);
	tmp_string = ft_read_conversation(&s[*i], args);
	//printf("\nafter  conversation tmp_string = %s char = %c i = %i\n", tmp_string, s[*i], *i);
	if (tmp_string)
	{
		//printf("\nbefore applying flags\n");
		tmp_string = ft_apply_flags(tmp_string, flags);
		//printf("\nafter  applying flags\n");
		return (ft_write_string(tmp_string, flags->conversion));
	}
	free(flags);
	return 	(0);
}

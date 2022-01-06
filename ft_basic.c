/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:54:01 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 18:56:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static char	*ft_create_percentage(void);

char	*ft_read_conversation(const char *s, va_list *args)
{
	if (*s == 'c')
		return (ft_read_char(args));
	else if (*s == 's')
		return (ft_read_string(args));
	else if (*s == 'p')
		return (ft_read_pointer(args));
	else if (*s == 'd')
		return (ft_itoa((int) va_arg(*args, int)));
	else if (*s == 'i')
		return (ft_itoa((int) va_arg(*args, int)));
	else if (*s == 'u')
		return (ft_itoa((unsigned int) va_arg(*args, unsigned int)));
	else if (*s == 'x')
		return (ft_read_hex(args, *s));
	else if (*s == 'X')
		return (ft_read_hex(args, *s));
	else if (*s == '%')
		return (ft_create_percentage());
	else
		return (ft_strdup(""));
}

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	free(s);
	return (i);
}

static char	*ft_create_percentage(void)
{
	char	percent[2];

	percent[0] = '%';
	percent[1] = '\0';
	return (ft_strdup(percent));
}

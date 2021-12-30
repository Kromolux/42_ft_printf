/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:39:00 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/30 15:04:37 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static char	*ft_read_conversation(const char *s, va_list *args);
static int	ft_write_char(char c);
static int	ft_write_string(char *s);
static char	*ft_create_percentage(void);

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
			//ft_read_flags(&s[i], %i);
			i++;
			tmp_string = ft_read_conversation(&s[i], &args);
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

static char	*ft_read_conversation(const char *s, va_list *args)
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

static int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_write_string(char *s)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:25:12 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 08:49:59 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_read_char(va_list *args)
{
	char	*tmp_string;

	tmp_string = (char *) malloc(sizeof(char) * 2);
	if (!tmp_string)
		return (NULL);
	tmp_string[0] = (char)((int) va_arg(*args, int));
	tmp_string[1] = '\0';
	return (tmp_string);
}

char	*ft_read_string(va_list *args)
{
	char	*tmp_string;
	char	*ptr;
	size_t	args_len;

	ptr = (char *) va_arg(*args, char *);
	args_len = ft_strlen(ptr) + 1;
	tmp_string = (char *) malloc(args_len);
	if (!tmp_string)
		return (NULL);
	ft_strlcpy(tmp_string, ptr, args_len);
	return (tmp_string);
}

char	*ft_read_pointer(va_list *args)
{
	char				*tmp_string;
	unsigned long long	memory_address;
	char				*ptr;

	tmp_string = (char *) malloc(sizeof(char) * 19);
	if (!tmp_string)
		return (NULL);
	memory_address = va_arg(*args, unsigned long long);
	ptr = (char *) &memory_address;
	tmp_string[0] = '0';
	tmp_string[1] = 'x';
	ft_create_hex_string(&tmp_string[2], ptr, 8, 0);
	return (tmp_string);
}

char	*ft_read_hex(va_list *args, char c)
{
	char			*tmp_string;
	unsigned int	tmp_ui;
	char			*ptr;
	int				i;

	tmp_string = (char *) malloc(sizeof(char) * 9);
	if (!tmp_string)
		return (NULL);
	tmp_ui = (unsigned int) va_arg(*args, unsigned int);
	ptr = (char *) &tmp_ui;
	ft_create_hex_string(tmp_string, ptr, 4, 0);
	if (c == 'X')
	{
		i = 0;
		while (tmp_string[i])
		{
			if (tmp_string[i] >= 'a' && tmp_string[i] <= 'f')
				tmp_string[i] -= 32;
			i++;
		}
	}
	return (tmp_string);
}

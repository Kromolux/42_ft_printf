/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:24:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/05 19:19:20 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "libft/libft.h"

static t_flags	*ft_initialize_flags(void);
static int		ft_read_number(const char *s, int *i);

t_flags	*ft_read_flags(const char *s, int *i)
{
	t_flags	*flags;
	
	flags = ft_initialize_flags();
	while (1)
	{
		if (s[*i] == '-')
			flags->left_aligned = ft_read_number(s, i);
		else if (s[*i] == '0')
			flags->leading_zeros = 1;
		else if (s[*i] == '.')
			flags->precision = ft_read_number(s, i);
		else if (s[*i] == '#')
			flags->leading_zeros_x = 1;
		else if (s[*i] == ' ')
			flags->leading_whitespace = 1;
		else if (s[*i] == '+')
			flags->leading_plus = 1;
		else if (s[*i] >= '1' && s[*i] <= '9')
			flags->right_aligned = ft_read_number(s, i);
		else
			return (flags);
		(*i)++;
	}
	return (flags);
}

static t_flags	*ft_initialize_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *) malloc(sizeof(*flags));
	if (!flags)
		return (NULL);
	flags->left_aligned = -1;
	flags->right_aligned = -1;
	flags->leading_zeros = -1;
	flags->precision = -1;
	flags->leading_zeros_x = -1;
	flags->leading_whitespace = -1;
	flags->leading_plus = -1;
	return (flags);
}

static int	ft_read_number(const char *s, int *i)
{
	int	count_of_numbers;

	(*i)++;
	count_of_numbers = ft_atoi(&s[*i]);
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	return (count_of_numbers);
}
/*
static int	ft_read_precision(const char *s, int *i)
{
	int	count_of_numbers;

	i++;
	count_of_numbers = ft_atoi(&s[*i]);
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	return (count_of_numbers);
}
*/
#include <stdio.h>
char	*ft_apply_flags(char *s, const char c, t_flags *flags)
{
	char	*prefix;
	
	prefix = '\0';
	if (flags->leading_zeros_x == 1 && (c == 'x' || c =='X' ))
	{
		prefix[0] = '0';
		printf("\nprefix after 0x \"%s\"\n", prefix);
		prefix[1] = c;
		prefix[2] = '\0';
		printf("\nprefix after 0x \"%s\"\n", prefix);
	}
	else if (flags->leading_plus == 1 && ( c == 'd' || c == 'i') && s[0] != '-')
		prefix = "+";
	else if (flags->leading_whitespace == 1 && ( c == 'd' || c == 'i') && s[0] != '-')
		prefix = " ";
	if (prefix)
	{
		prefix = ft_strjoin(prefix, s);
		free(s);
	}
	free(flags);
	return (prefix);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:06:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/08 21:45:10 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "libft/libft.h"
#include <stdio.h>
static t_flags	*ft_initialize_flags(void);
static int		ft_read_number(const char *s, int *i);
static int		ft_set_flag(int *flag, int value);
static void		ft_read_width(const char *s, int *i, t_flags *flags);

t_flags	*ft_read_flags(const char *s, int *i)
{
	t_flags	*flags;
	
	flags = ft_initialize_flags();
	while (1)
	{
		if (s[*i] == '-')
			flags->left_aligned = ft_read_number(s, i);
		else if (s[*i] == '0')
			(*i) += ft_set_flag(&flags->leading_zeros, 1);
		else if (s[*i] == '.')
			flags->precision = ft_read_number(s, i);
		else if (s[*i] == '#')
			(*i) += ft_set_flag(&flags->leading_zeros_x, 1);
		else if (s[*i] == ' ')
			(*i) += ft_set_flag(&flags->leading_whitespace, 1);
		else if (s[*i] == '+')
			(*i) += ft_set_flag(&flags->leading_plus, 1);
		else if (s[*i] >= '1' && s[*i] <= '9')
			ft_read_width(s, i, flags);
		else if (ft_strchr("cspdiuxX%%", s[*i]) != NULL)
		{
			flags->conversion = s[*i];
			return (flags);
		}
	}
	return (flags);
}

static t_flags	*ft_initialize_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(*flags));
	if (!flags)
		return (NULL);
	flags->left_aligned = -1;
	flags->right_aligned = -1;
	flags->leading_zeros = -1;
	flags->precision = -1;
	flags->leading_zeros_x = -1;
	flags->leading_whitespace = -1;
	flags->leading_plus = -1;
	flags->conversion = '\0';
	return (flags);
}

static int	ft_read_number(const char *s, int *i)
{
	int	count_of_numbers;

	//printf("i = %i string %s\n", *i, s);
	if (s[*i] == '-' || s[*i] == '.')
		(*i)++;
	count_of_numbers = ft_atoi(&s[*i]);
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	return (count_of_numbers);
}

static int	ft_set_flag(int *flag, int value)
{
	*flag = value;
	return (1);
}

static void	ft_read_width(const char *s, int *i, t_flags *flags)
{
	if (flags->left_aligned == -1)
		flags->right_aligned = ft_read_number(s, i);
	else
		flags->left_aligned = ft_read_number(s, i);
}

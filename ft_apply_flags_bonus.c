/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:24:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/10 17:57:03 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "libft/libft.h"

static char		*ft_create_zero_x(char c, char *input);
static char		*ft_apply_precision(char *s, t_flags *flags);
static char		*ft_apply_right_aligned(char *prefix, char *s, t_flags *flags);
static char		*ft_apply_left_aligned(char *prefix, char *s, t_flags *flags);
static char		*ft_add_char(char c, int count);
#include <stdio.h>

char	*ft_apply_flags(char *s, t_flags *flags)
{
	char	*prefix;
	char	c;
	char	*tmp;

	c = flags->conversion;
	prefix = (char *) malloc(sizeof(char) * 2);
	if (!prefix)
		return (NULL);
	prefix[0] = '\0';
	prefix[1] = '\0';
	if (flags->leading_zeros_x == 1 && (c == 'x' || c =='X' ) && s[0] != '0')
		prefix = ft_create_zero_x(c, prefix);
	else if (flags->leading_plus == 1 && ( c == 'd' || c == 'i') && s[0] != '-')
		prefix[0] = '+';
	else if (flags->leading_whitespace == 1 && ( c == 'd' || c == 'i') && s[0] != '-')
		prefix[0] = ' ';
	if (flags->precision >= 0)
		s = ft_apply_precision(s, flags);
	if (flags->right_aligned > 0)
		prefix = ft_apply_right_aligned(prefix, s, flags);
	//printf("string = %s\n", s);
	if (flags->left_aligned > 0)
		s = ft_apply_left_aligned(prefix, s, flags);
	//printf("ft_strjoin\n");
	tmp = ft_strjoin(prefix, s);
	//printf("\nfreed prefix [%s] tmp [%s]\n", prefix, tmp);
	free(prefix);
	//printf("\nfreed s\n");
	free(s);
	return (tmp);
}

static char	*ft_create_zero_x(char c, char *input)
{
	char	*output;
	

	output = (char *) malloc(sizeof(char) * 3);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = c;
	output[2] = '\0';
	//printf("ft_create_zero_x = [%s]\n", output);
	free(input);
	return (output);
}

#include <stdio.h>
static char		*ft_apply_precision(char *s, t_flags *flags)
{
	int		s_len;
	char	*prefix;
	int		offset;
	char	*tmp1;
	char	*tmp2;

	prefix = (char *) malloc(sizeof(char) * 2);
	s_len = ft_strlen(s);
	if (s_len == 0)
		s_len = 1;
	prefix[0] = '\0';
	prefix[1] = '\0';
	offset = 0;
	//printf("precision = %i string = %s char = %c prefix = %s\n", flags->precision, s, flags->conversion, prefix);
	if (s[0] == '-' || s[0] == '+')
	{
		s_len--;
		tmp1 = ft_add_char(s[0], 1);
		free(prefix);
		prefix = tmp1;
		offset++;
	}
	//printf("precision = %i string = %s char = %c prefix = %s\n", flags->precision, s, flags->conversion, prefix);
	if (flags->conversion == 's')
		s[flags->precision] = '\0';
	else if (ft_strchr("diuxX", flags->conversion))
	{
		if (s_len < flags->precision)
		{
			tmp1 = ft_add_char('0', flags->precision - s_len);
			tmp2 = ft_strjoin(prefix, tmp1);
			free(prefix);
			free(tmp1);
			//printf("adding zeros to the string = %s = %s\n", prefix, s);
			tmp1 = ft_strjoin(tmp2, &s[offset]);
			free(s);
			s = tmp1;
			free(tmp2);
			//printf("result = %s\n", s);
		}
		else if (s_len == 1 && s[0] == '0')
			s[0] = '\0';
	}
	return (s);
}

static char		*ft_apply_right_aligned(char *prefix, char *s, t_flags *flags)
{
	int		s_len;
	int		prefix_len;
	char	c;
	char	*tmp1;
	char	*tmp2;

	s_len = ft_strlen(s);
	if (s_len == 0)
		s_len = 1;
	prefix_len = ft_strlen(prefix);
	//printf("prefix = %s prefix_len %i s_len = %i\n", prefix, prefix_len, s_len);
	if (ft_strchr("cspdiuxX", flags->conversion) && (prefix_len + s_len) < flags->right_aligned)
	{
		if (flags->leading_zeros == 1)
			c = '0';
		else
			c = ' ';
		if (prefix[1] == 'x' || prefix[1] == 'X')
		{
			tmp1 = ft_add_char(c, flags->right_aligned - (prefix_len + s_len));
			tmp2 = ft_strjoin(prefix, tmp1);
			free(tmp1);
			free(prefix);
			prefix = tmp2;
		}
		else
		{
			tmp1 = ft_add_char(c, flags->right_aligned - (prefix_len + s_len));
			tmp2 = ft_strjoin(tmp1, prefix);
			free(tmp1);
			free(prefix);
			prefix = tmp2;
		}
	}
	//free(s);
	//printf("prefix before return = [%s]\n", prefix);
	return (prefix);
}

static char	*ft_add_char(char c, int count)
{
	char	*tmp;
	int		i;
	
	i = 0;
	tmp = (char *) malloc(sizeof(char) * count);
	if (!tmp)
		return (NULL);
	while (i < count)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char		*ft_apply_left_aligned(char *prefix, char *s, t_flags *flags)
{
	int		s_len;
	int		prefix_len;
	char	*tmp1;
	char	*tmp2;

	s_len = ft_strlen(s);
	if (s_len == 0)
		s_len = 1;
	prefix_len = ft_strlen(prefix);
	//printf("prefix = %s prefix_len %i s_len = %i\n", prefix, prefix_len, s_len);
	if (ft_strchr("cspdiuxX", flags->conversion) && (prefix_len + s_len) < flags->left_aligned)
	{
		tmp1 = ft_add_char(' ', flags->left_aligned - (prefix_len + s_len));
		tmp2 = ft_strjoin(s, tmp1);
		free(tmp1);
		free(s);
		s = tmp2;
	}
	//printf("prefix = %s\n", prefix);
	//if (flags->conversion == 'd')
	//free(s);
	//printf("prefix before return = [%s]\n", prefix);
	return (s);
}

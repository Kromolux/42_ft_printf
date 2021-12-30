/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:57:19 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/29 20:31:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static void	ft_convert_to_hex(char *output, char c);

void	ft_create_hex_string(char *output, char *input, int n,
			int leading_zeros)
{
	int		i;

	i = 0;
	n--;
	if (leading_zeros == 0)
	{
		while (input[n] == (char) 0)
			n--;
		ft_convert_to_hex(&output[i], input[n]);
		if (leading_zeros == 1 && output[i] == '0')
		{
			output[i] = output[i + 1];
			i++;
		}
	}
	while (n >= 0)
	{
		ft_convert_to_hex(&output[i], input[n]);
		i += 2;
		n--;
	}
	output[i] = '\0';
}

static void	ft_convert_to_hex(char *output, char c)
{
	char	*hex_mask;

	hex_mask = "0123456789abcdef";
	output[0] = hex_mask[(c >> 4) & 15];
	output[1] = hex_mask[c & 15];
}

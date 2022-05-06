/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 06:27:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/12 15:09:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_string(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 'c' && i == 0)
		i = 1;
	write(1, s, i);
	free(s);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 06:27:38 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/10 17:45:35 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_string(char *s, char conversion)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (conversion == 'c' && i == 0)
		i = 1;
	write(1, s, i);
	free(s);
	return (i);
}

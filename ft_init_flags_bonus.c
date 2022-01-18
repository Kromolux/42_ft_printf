/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:48:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/13 13:52:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

t_flags	*ft_initialize_flags(void)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:57:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/02 16:21:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (n > 0)
	{
		i = 0;
		if (dest < src)
		{
			while (i < n)
			{
				((char *) dest)[i] = ((char *) src)[i];
				i++;
			}
		}
		else
		{
			while (i < n)
			{
				((char *) dest)[n - i - 1] = ((char *) src)[n - i - 1];
				i++;
			}
		}
	}
	return (dest);
}

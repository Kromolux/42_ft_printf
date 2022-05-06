/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_tools_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:12:55 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/13 16:22:42 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

char	*ft_realloc(char *dst, char *src, int free_dst, int free_src)
{
	char	*output;
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	output = (char *) ft_malloc_and_zero_mem(dst_len + src_len + 1);
	if (!output)
		return (NULL);
	i = ft_copy(output, dst, 0);
	ft_copy(&output[i], src, 0);
	if (free_dst)
		free(dst);
	if (free_src)
		free(src);
	return (output);
}

size_t	ft_copy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		size--;
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (i);
}

void	*ft_malloc_and_zero_mem(size_t size)
{
	size_t	i;
	void	*output;

	i = 0;
	output = malloc(sizeof(char) * (size));
	if (!output)
		return (NULL);
	while (i < size)
	{
		((char *) output)[i] = '\0';
		i++;
	}
	return (output);
}

char	*ft_create_zero_x(char c, char *input)
{
	char	*output;

	output = (char *) malloc(sizeof(char) * 3);
	if (!output)
		return (NULL);
	output[0] = '0';
	output[1] = c;
	output[2] = '\0';
	free(input);
	return (output);
}

char	*ft_add_char(char c, size_t count)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *) malloc(sizeof(char) * count + 1);
	if (!output)
		return (NULL);
	while (i < count)
	{
		output[i] = c;
		i++;
	}
	output[i] = '\0';
	return (output);
}

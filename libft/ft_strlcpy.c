/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:33:04 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:44:44 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	src_size(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	unsigned int	i;
	int				s_size;

	i = 0;
	s_size = src_size((char *)src);
	if (size == 0)
		return (s_size);
	while (*src && (i < size - 1 && (size != 0)))
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:30:05 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:43:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*plcdst;
	char	*plcsrc;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			plcdst = dst + (len - 1);
			plcsrc = (char *)src + (len - 1);
			*plcdst = *plcsrc;
			len--;
		}
		return (dst);
	}
	plcdst = dst;
	while (len > 0)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
		len--;
	}
	return (plcdst);
}

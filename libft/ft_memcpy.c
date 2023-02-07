/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:01:58 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:43:43 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = (char *)dst;
	psrc = (char *)src;
	while (n > 0)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (dst);
}

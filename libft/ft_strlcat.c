/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:08:28 by makacem           #+#    #+#             */
/*   Updated: 2021/12/17 11:41:15 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	int		src_len;
	char	*pdst_lc;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	pdst_lc = dst + dst_len;
	while (src_len > 0 && dstsize - 1 > dst_len)
	{
		*pdst_lc++ = *src++;
		dstsize--;
		src_len--;
	}
	*pdst_lc = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

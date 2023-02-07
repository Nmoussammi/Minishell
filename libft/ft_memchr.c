/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:43:26 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:43:36 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pc;

	pc = (unsigned char *)s;
	while (n > 0)
	{
		if (*pc == (unsigned char)c)
		{
			return (pc);
		}
		pc++;
		n--;
	}
	return (NULL);
}

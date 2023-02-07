/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:38:25 by makacem           #+#    #+#             */
/*   Updated: 2022/06/06 10:02:28 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pc;
	int		str_len;
	char	cc;

	cc = (char)c;
	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s == (void *)0)
		return ((char *)s);
	s = s + str_len;
	while (str_len + 1 > 0)
	{
		if (*s == cc)
		{
			pc = (char *)s;
			return (pc);
		}
		str_len--;
		s--;
	}
	return (NULL);
}

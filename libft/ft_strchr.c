/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:16:48 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:44:25 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	char	cc;

	cc = (char)c;
	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == cc)
			return (ps);
		ps++;
	}
	if (*ps == cc)
		return (ps);
	return (NULL);
}

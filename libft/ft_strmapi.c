/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:47:27 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:44:54 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ps;
	int				len;
	unsigned int	i;

	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	ps = malloc((len + 1) * sizeof(char));
	if (ps == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ps[i] = (*f)(i, (char)s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}

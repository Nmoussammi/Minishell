/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:34:35 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:45:06 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*phaystack;
	char	*pneedle;
	size_t	i;

	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack && len > 0)
	{
		phaystack = ((char *)haystack);
		pneedle = ((char *)needle);
		i = len;
		while (*phaystack == *pneedle && i > 0)
		{
			phaystack++;
			pneedle++;
			i--;
			if (*pneedle == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}

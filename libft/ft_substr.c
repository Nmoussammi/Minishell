/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:15:59 by makacem           #+#    #+#             */
/*   Updated: 2022/12/26 15:12:43 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*ptr;
	char	*pstart;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		ptr = malloc(ft_strlen(s));
	else
		ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	pstart = ptr;
	i = start;
	while (s[i] != '\0' && (len > 0) && i < (int)ft_strlen(s))
	{
		*ptr = s[i];
		ptr++;
		i++;
		len--;
	}
	*ptr = '\0';
	return (pstart);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:59:35 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:44:31 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ps1;
	char	*pps1;

	size = ft_strlen(s1);
	ps1 = malloc(size + 1);
	if (ps1 == NULL)
		return (NULL);
	pps1 = ps1;
	while (*s1)
	{
		*pps1 = *s1;
		pps1++;
		s1++;
	}
	*pps1 = '\0';
	return (ps1);
}

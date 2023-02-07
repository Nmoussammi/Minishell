/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:19:53 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:45:15 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skips1(char *s1, char *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i1;
	char	*ptr;
	char	*p_lc_s1;
	char	*p_lc_ptr;
	int		len;

	if (!s1 || !set)
		return (0);
	if (*set == '\0')
		return (ft_strdup(s1));
	i1 = 0;
	s1 = ft_skips1((char *)s1, (char *)set);
	p_lc_s1 = (char *)s1 + ft_strlen(s1);
	while (ft_strrchr(set, *(p_lc_s1--)))
		i1++;
	len = ft_strlen(s1) - i1 + 2;
	if (len <= 0)
		len = 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	p_lc_ptr = ptr + ft_strlen(ptr) + 1;
	*p_lc_ptr = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:40:17 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 16:41:42 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_invalid_read_check(char **arr)
{
	arr = malloc(sizeof(char **));
	arr[0] = NULL;
	return (arr);
}

static int	ft_countnstr(char const *str, char c)
{
	int	count;

	if (c == 0)
		return (1);
	count = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str != c && *str != '\0')
			str++;
		while (*str == c)
			str++;
		count++;
	}
	return (count);
}

static char	*ft_make_mini_s(char *s, char c)
{
	int		i;
	int		len;
	char	*mini_s;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	if (*s == '\0')
		c = '\0';
	len = ft_strlen(s - i) - ft_strlen(ft_strchr(s - i, c)) + 1;
	mini_s = malloc(len);
	ft_strlcpy(mini_s, (s - i), len);
	return (mini_s);
}

static char	*ft_skip_s_c(char *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_s;
	int		count;
	int		j;

	if (!s)
		return (0);
	if (*s == 0)
	{
		splited_s = NULL;
		return (ft_invalid_read_check(splited_s));
	}
	count = ft_countnstr(s, c);
	splited_s = malloc((count + 1) * sizeof * splited_s);
	if (!splited_s)
		return (NULL);
	j = 0;
	while (j < count)
	{
		splited_s[j++] = ft_make_mini_s((char *)s, c);
		s = ft_skip_s_c((char *)s, c);
	}
	splited_s[j] = NULL;
	return (splited_s);
}

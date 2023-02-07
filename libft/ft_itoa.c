/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:14:33 by makacem           #+#    #+#             */
/*   Updated: 2021/12/15 21:43:32 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(long int n)
{
	int	i;

	if (n < 0)
		n = -n;
	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_work(char *s, long int nb, int count)
{
	if (nb < 0)
	{
		nb = -nb;
		while (count > 0)
		{
			*(s + count) = (nb % 10) + 48;
			nb = nb / 10;
			count--;
		}
	}
	while (count > 0)
	{
		*(s + count - 1) = (nb % 10) + 48;
		nb = nb / 10;
		count--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*strnbr;
	int			count;
	long int	nb;

	nb = n;
	count = ft_countdigit(nb);
	if (n < 0)
	{
		strnbr = malloc(count + 2);
		if (strnbr == NULL)
			return (NULL);
		strnbr[0] = '-';
		strnbr[count + 1] = '\0';
		ft_work(strnbr, nb, count);
		return (strnbr);
	}
	strnbr = malloc(count + 1);
	if (strnbr == NULL)
		return (NULL);
	strnbr[count] = '\0';
	ft_work(strnbr, nb, count);
	return (strnbr);
}

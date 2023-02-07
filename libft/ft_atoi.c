/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:39:08 by makacem           #+#    #+#             */
/*   Updated: 2022/09/27 19:51:38 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long int	n;
	int			a;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	a = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			a = a * -1;
		str++;
	}
	n = 0;
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	return (n * a);
}

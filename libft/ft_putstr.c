/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:09:28 by makacem           #+#    #+#             */
/*   Updated: 2022/06/15 10:31:12 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s)
	{
		ret += ft_putchar(*s);
		s++;
	}
	return (ret);
}

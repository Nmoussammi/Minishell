/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:32:25 by makacem           #+#    #+#             */
/*   Updated: 2022/06/15 10:29:43 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrhexa(unsigned long int nb)
{
	static int	ret;
	char		*base;

	ret = 0;
	base = "0123456789abcdef";
	if (nb <= 15)
		ret += ft_putchar(base[nb]);
	else if (nb >= 16)
	{
		ft_putnbrhexa(nb / 16);
		ret += ft_putchar(base[nb % 16]);
	}
	return (ret);
}

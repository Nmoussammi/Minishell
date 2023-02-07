/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexaup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:50:43 by makacem           #+#    #+#             */
/*   Updated: 2022/06/15 10:30:43 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrhexaup(unsigned long int nb)
{
	static int	ret;
	char		*base;

	ret = 0;
	base = "0123456789ABCDEF";
	if (nb <= 15)
		ret += ft_putchar(base[nb]);
	else if (nb >= 16)
	{
		ft_putnbrhexaup(nb / 16);
		ret += ft_putchar(base[nb % 16]);
	}
	return (ret);
}

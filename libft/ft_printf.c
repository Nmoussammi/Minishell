/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:52:48 by makacem           #+#    #+#             */
/*   Updated: 2022/06/15 10:26:16 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strpp(char *str)
{
	str++;
	str++;
	return (str);
}

static int	paramchaeck(char *str, va_list args)
{
	int	ret;

	ret = 0;
	if (*(str + 1) == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (*(str + 1) == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
	{
		ret += ft_putstr("0x");
		ret += ft_putnbrhexa((unsigned long int)va_arg(args, void *));
	}
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		ret += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'u')
		ret += ft_putnbr(va_arg(args, unsigned int));
	else if (*(str + 1) == 'x')
		ret += ft_putnbrhexa(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		ret += ft_putnbrhexaup(va_arg(args, unsigned int));
	else if (*(str + 1) == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	static int	ret;

	va_start(args, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ret += paramchaeck((char *) str, args);
			str = ft_strpp((char *)str);
		}
		else
		{
			ret += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (ret);
}

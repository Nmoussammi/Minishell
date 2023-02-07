/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:14:50 by makacem           #+#    #+#             */
/*   Updated: 2022/09/06 16:05:00 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero((char *)ptr, count * size);
	return ((void *)ptr);
}

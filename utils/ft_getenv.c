/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:45 by makacem           #+#    #+#             */
/*   Updated: 2023/01/14 21:50:51 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(char	**env, char *var)
{
	char	*content;
	char	**arr;

	arr = env;
	content = NULL;
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, var, ft_strlen(var)) == 0)
		{
			content = ft_strchr(*arr, '=');
			content++;
			return (content);
		}
		arr++;
	}
	return (content);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:30 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 21:39:22 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_env_var(char	**env)
{
	int	nbrof_env_var;

	nbrof_env_var = 0;
	while (*env != '\0')
	{
		nbrof_env_var++;
		env++;
	}
	return (nbrof_env_var);
}

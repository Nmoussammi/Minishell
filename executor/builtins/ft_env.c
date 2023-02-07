/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_print_contenv(char *var);
char	**ft_env_err(char	**env);
void	ft_print_envenv(char	**arr);

char	**ft_env(int n_cmd, char **cmd, char **env)
{
	char	**arr;

	cmd = NULL;
	if (n_cmd > 1)
		return (ft_env_err(env));
	arr = env;
	ft_print_envenv(arr);
	g_global.exit_status = 0;
	return (g_global.exit_status = 0, env);
}

void	ft_print_envenv(char	**arr)
{
	char	*var;

	while (*arr != NULL)
	{
		if (ft_strchr(*arr, '=') != NULL)
		{
			var = *arr;
			while (*var != '=' && *var != '\0')
			{
				ft_putchar(*var);
				var++;
				if (*var == '+')
					var++;
			}
			if (*var != '\0')
				ft_print_contenv(var);
			ft_putchar('\n');
		}
		arr++;
	}
}

void	ft_print_contenv(char *var)
{
	ft_putchar('=');
	var++;
	ft_printf("%s", var);
}

char	**ft_env_err(char	**env)
{
	ft_printf("env: usage: with no options or arguments\n");
	g_global.exit_status = 1;
	return (env);
}

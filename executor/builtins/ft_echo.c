/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:49:15 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/17 21:42:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_alphabet(char *str, char alphabet)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != alphabet)
			return (0);
		i++;
	}
	return (1);
}

void	echo_utils(int n_cmd, char **cmd, int i, int val)
{
	while (i < n_cmd && cmd[i][0] == '-' && cmd[i][1] == 'n' \
		&& check_alphabet(cmd[i], 'n') == 1)
	{
		val = 1;
		i++;
	}
	while (val == 0 && i < n_cmd)
	{
		ft_printf("%s", cmd[i]);
		if (i != n_cmd - 1)
			ft_printf(" ");
		i++;
	}
	if (val == 0)
		ft_printf("\n");
	while (val == 1 && i < n_cmd && cmd[i] != NULL)
	{
		ft_printf("%s", cmd[i]);
		if (i != n_cmd - 1)
			ft_printf(" ");
		i++;
	}
}

char	**ft_echo(int n_cmd, char **cmd, char **env)
{
	int	i;
	int	val;

	val = 0;
	i = 1;
	if (cmd[i] == NULL)
		ft_printf("\n");
	else
		echo_utils(n_cmd, cmd, i, val);
	g_global.exit_status = 0;
	return (env);
}

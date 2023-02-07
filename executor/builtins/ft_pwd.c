/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:50:21 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_pwd(int n_cmd, char **cmd, char **env)
{
	char	buff[1245];

	if (n_cmd > 1 && cmd[1][0] == '-' && cmd[1][1] != '\0')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", \
		cmd[1][1]);
		g_global.exit_status = 1;
		return (env);
	}
	getcwd(buff, 1245);
	printf("%s\n", buff);
	g_global.exit_status = 0;
	return (env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:31:37 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	path_exist(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**path(t_treenode *root, char **env)
{
	char	*str;
	char	**split_path;

	root = NULL;
	str = ft_getenv(env, "PATH");
	if (!str)
	{
		g_global.exit_status = 127;
		return (NULL);
	}
	else
	{
		split_path = ft_split(str, ':');
		if (!split_path)
			return (NULL);
		return (split_path);
	}
}

void	ft_print(t_treenode *root, char *cmd, char *tmp)
{
	free(tmp);
	ft_dupin_close(root->stdin_fd, root->temp_fdin);
	ft_dupout_close(root->stdout_fd, root->temp_fdout);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_global.exit_status = 127;
}

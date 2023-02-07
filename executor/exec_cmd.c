/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:03:11 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:22:30 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_path(char **str)
{
	char	**arr;

	if (str != NULL)
	{
		arr = str;
		while (*arr != NULL)
		{
			free(*arr);
			arr++;
		}
		free(str);
	}
}

void	find_and_exec(t_treenode *root, char **str, char **env)
{
	int		i;
	char	*tmp;
	char	*path;

	tmp = ft_strjoin("/", root->cmd[0]);
	if (!tmp)
		return (ft_free_path(str), (void)0);
	i = 0;
	while (str[i])
	{
		path = ft_strjoin(str[i], tmp);
		if (!path)
			return (ft_free_path(str), free(tmp), (void)0);
		else if (exec_file(root, path, env) == 0)
		{
			i++;
			free(path);
		}
		else
			return (free(path), free(tmp), (void)0);
	}
	if (str[i] == NULL)
		ft_print(root, root->cmd[0], tmp);
}

void	ft_exec_cmd_utils(t_treenode *root, char **env, char **str)
{
	if (root->cmd[0][1] == '\0')
	{
		ft_dupin_close(root->stdin_fd, root->temp_fdin);
		ft_dupout_close(root->stdout_fd, root->temp_fdout);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(root->cmd[0], 2);
		ft_putstr_fd(": is a directory\n", 2);
		g_global.exit_status = 126;
		ft_free_path(str);
		return ;
	}
	else if (exec_file(root, root->cmd[0], env) == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(root->cmd[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		ft_free_path(str);
		g_global.exit_status = 127;
		return ;
	}
	ft_free_path(str);
}

void	ft_exec_cmd(t_treenode	*root, char **env)
{
	char	**str;

	str = path(root, env);
	if (path_exist(root->cmd[0]) == 1)
		ft_exec_cmd_utils(root, env, str);
	else if (!str)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(root->cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_global.exit_status = 127;
		return ;
	}
	else
	{
		find_and_exec(root, str, env);
		ft_free_path(str);
	}
}

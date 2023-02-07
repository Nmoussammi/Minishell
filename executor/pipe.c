/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:56:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:33:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute_utils(int *fd, t_treenode *root, char **env, int id)
{
	if (id == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_execute_rec(root->right, env);
		exit(g_global.exit_status);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		ft_execute_rec(root->left, env);
		exit(g_global.exit_status);
	}
}

void	ft_pipe(t_treenode *root, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	val;

	val = pipe(fd);
	if (val == -1)
		return ;
	pid1 = fork();
	if (pid1 == 0)
		ft_execute_utils(fd, root, env, 0);
	pid2 = fork();
	if (pid2 == 0)
		ft_execute_utils(fd, root, env, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &g_global.exit_status, 0);
	waitpid(pid2, &g_global.exit_status, 0);
	check_signal();
}

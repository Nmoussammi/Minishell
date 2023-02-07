/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:08:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:51:38 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_signal(void)
{
	if (WIFSIGNALED(g_global.exit_status))
	{
		g_global.exit_status = WTERMSIG(g_global.exit_status);
		if (g_global.exit_status == SIGINT)
		{
			g_global.sig_cat = 1;
			write(2, "\n", 1);
		}
		else if (g_global.exit_status == SIGQUIT)
		{
			write(2, "Quit: 3\n", 9);
		}
		g_global.exit_status += 128;
	}
	else
	{
		g_global.exit_status = WEXITSTATUS(g_global.exit_status);
	}
}

void	putstr_utils(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	g_global.exit_status = 1;
}

int	exec_file(t_treenode *root, char *path, char **env)
{
	int	pid;

	if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
			putstr_utils();
		else if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			if (execve(path, root->cmd, env) == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(root->cmd[0], 2);
				ft_putstr_fd(": is directory\n", 2);
				exit(126);
			}
		}
		wait(&g_global.exit_status);
		check_signal();
		return (1);
	}
	return (0);
}

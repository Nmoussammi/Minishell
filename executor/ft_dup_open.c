/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:51:55 by makacem           #+#    #+#             */
/*   Updated: 2023/01/13 13:16:03 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_dupin_open(int fd_stdin)
{
	int		temp_fdin;

	temp_fdin = 0;
	if (fd_stdin != 0)
	{
		temp_fdin = dup(STDIN_FILENO);
		dup2(fd_stdin, STDIN_FILENO);
	}
	return (temp_fdin);
}

int	ft_dupout_open(int fd_stdout)
{
	int		temp_fdout;

	temp_fdout = 0;
	if (fd_stdout != 0)
	{
		temp_fdout = dup(STDOUT_FILENO);
		dup2(fd_stdout, STDOUT_FILENO);
	}
	return (temp_fdout);
}

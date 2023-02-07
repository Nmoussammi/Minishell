/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:57:24 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 11:10:54 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dupin_close(int fd_stdin, int temp_fdin)
{
	if (fd_stdin != 0 && temp_fdin != 0)
	{
		dup2(temp_fdin, STDIN_FILENO);
		close(fd_stdin);
	}
}

void	ft_dupout_close(int fd_stdout, int temp_fdout)
{
	if (fd_stdout != 0 && temp_fdout != 0)
	{
		dup2(temp_fdout, STDOUT_FILENO);
		close(fd_stdout);
	}
}

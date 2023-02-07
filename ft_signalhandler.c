/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 21:41:00 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGINT && g_global.sig == 0 && g_global.sig_cat != 1)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		rl_done = 1;
		g_global.exit_heredoc = 0;
	}
}

void	handling_sig(void)
{
	rl_catch_signals = 0;
	if (signal(SIGINT, handler) == SIG_ERR || \
	signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		write(2, "sig error\n", 10);
		exit(1);
	}
}

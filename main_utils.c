/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:17 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:09:47 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar22(int c)
{
	write(1, &c, 1);
	return (1);
}

int	event(void)
{
	return (0);
}

int	main_utils(char *line)
{
	char	*sr_cap;

	g_global.exit_heredoc = 1;
	rl_event_hook = event;
	if (!line)
	{
		sr_cap = tgetstr("sr", NULL);
		tputs(sr_cap, 0, ft_putchar22);
		printf("minishell$ exit\n");
		exit(0);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

int	ft_pars_error(void)
{
	ft_putstr_fd("minishell: syntax error\n", 2);
	g_global.exit_status = 258;
	return (1);
}

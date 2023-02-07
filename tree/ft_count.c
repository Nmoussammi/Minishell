/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:02:31 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/14 22:03:05 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_cmds(char	**cmd)
{
	char	**temp;
	int		count;

	count = 0;
	temp = cmd;
	while (*temp != NULL)
	{
		count++;
		temp++;
	}
	return (count);
}

int	ft_count_words(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL)
	{
		if (token->type == WORD || token->type == REDIRECTION)
			count++;
		else if (token->type == PIPE)
			return (count);
		token = token->next;
	}
	return (count);
}

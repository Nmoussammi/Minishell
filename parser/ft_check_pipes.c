/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:31:57 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:38:22 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_pipe_space_pipe(t_token *token);

int	ft_check_pipes(t_token *token_list)
{
	t_token	*token;
	int		count;

	count = 0;
	token = token_list;
	while (token != NULL)
	{
		while ((token->type == DQUOTE || token->type == SQUOTE
				|| token->type == WORD) && token->next != NULL)
		{
			count++;
			token = token->next;
		}
		if (token->type == PIPE)
		{
			if (count == 0 || token->next == NULL || token->next->type == PIPE
				|| ft_pipe_space_pipe(token) == 1)
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int	ft_pipe_space_pipe(t_token *token)
{
	token = token->next;
	while (token->type == SPACEE)
	{
		token = token->next;
		if (token->type == PIPE)
			return (1);
	}
	return (0);
}

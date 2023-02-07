/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:01 by makacem           #+#    #+#             */
/*   Updated: 2023/01/13 15:20:26 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_redirec_null(t_token *token_list);
int	ft_more_redirec(t_token *token_list);
int	ft_diff_redirec(t_token *token_list);

int	ft_check_redirections(t_token *token_list)
{
	t_token	*token;

	if (ft_redirec_null(token_list) == 1 || ft_more_redirec(token_list) == 1
		|| ft_diff_redirec(token_list) == 1)
		return (1);
	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		if (token->type == REDIRECTION)
		{
			while (token->next != NULL)
			{
				if (token->type == PIPE)
					return (1);
				else if (token->type == WORD)
					return (0);
				token = token->next;
			}
		}
		token = token->next;
	}
	return (0);
}

int	ft_diff_redirec(t_token *token_list)
{
	t_token	*token;
	char	*temp;

	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		if (token->type == REDIRECTION && ft_strlen(token->name) == 2)
		{
			temp = token->name;
			if (*temp != *(temp + 1))
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int	ft_more_redirec(t_token *token_list)
{
	t_token	*token;
	int		count;

	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		count = 0;
		if (token->type == REDIRECTION)
		{
			count = ft_strlen(token->name);
			if (count > 2)
				return (1);
			token = token->next;
		}
		token = token->next;
	}
	return (0);
}

int	ft_redirec_null(t_token *token_list)
{
	t_token	*token;

	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		if (token->type == REDIRECTION && token->next == NULL)
			return (1);
		token = token->next;
	}
	return (0);
}

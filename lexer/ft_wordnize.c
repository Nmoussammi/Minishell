/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:52:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 15:18:05 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_fill_empty(t_token *temp_token);
void	ft_grp_wrds(t_token	*temp_token);

void	ft_wordnize_dq(t_token *token)
{
	t_token	*temp_token;

	temp_token = token;
	while (temp_token != NULL)
	{
		if (temp_token->next != NULL && temp_token->type == DQUOTE)
		{
			temp_token = temp_token->next;
			while (temp_token->next != NULL && temp_token->type != DQUOTE)
			{
				if (temp_token->type != DOLLAR)
					temp_token->type = WORD;
				temp_token = temp_token->next;
			}
		}
		temp_token = temp_token->next;
	}
}

void	ft_wordnize_sq(t_token *token)
{
	t_token	*temp_token;

	temp_token = token;
	while (temp_token != NULL)
	{
		if (temp_token->next != NULL && temp_token->type == SQUOTE)
		{
			temp_token = temp_token->next;
			while (temp_token->next != NULL && temp_token->type != SQUOTE)
			{
				temp_token->type = WORD;
				temp_token = temp_token->next;
			}
		}
		temp_token = temp_token->next;
	}
	ft_grp_wrds(token);
}

void	ft_grp_wrds(t_token	*temp_token)
{
	while (temp_token != NULL)
	{
		if (temp_token->next != NULL && temp_token->type == SQUOTE)
		{
			temp_token = temp_token->next;
			while (temp_token->next != NULL && temp_token->type != SQUOTE)
			{
				if (temp_token->type == WORD && temp_token->next->type == WORD)
					temp_token = ft_fill_empty(temp_token);
				else
					temp_token = temp_token->next;
			}
		}
		temp_token = temp_token->next;
	}
}

t_token	*ft_fill_empty(t_token *temp_token)
{
	char	*dollar;
	char	*var;
	t_token	*to_free;

	to_free = temp_token->next;
	dollar = temp_token->name;
	var = temp_token->next->name;
	temp_token->name = ft_strjoin(temp_token->name, temp_token->next->name);
	free(dollar);
	free(var);
	temp_token->next = temp_token->next->next;
	free(to_free);
	return (temp_token);
}

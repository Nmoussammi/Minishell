/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grp_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:34:05 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:37:03 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_join_tokens(char **str, t_token *token);
int		ft_check_type_diff_wsr(int token_type);
int		ft_check_type_is_wsr(int token_type);

t_token	*ft_grp_tokens(t_token *token)
{
	t_token	*list;
	t_token	*new_token;
	t_token	*temp;
	char	*str;

	list = (t_token *)malloc(sizeof(t_token));
	list->next = NULL;
	temp = list;
	while (token != NULL)
	{
		str = NULL;
		if (token->next == NULL || ft_check_type_diff_wsr(token->type))
			str = ft_strjoin(&token->value, "");
		else if (token->next == NULL || ft_check_type_is_wsr(token->type))
			str = ft_strjoin(&token->value, "");
		token = ft_join_tokens(&str, token);
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->type = token->type;
		new_token->name = str;
		new_token->next = NULL;
		temp->next = new_token;
		temp = temp->next;
		token = token->next;
	}
	return (list);
}

t_token	*ft_join_tokens(char **str, t_token *token)
{
	char	*temp_str;

	while (token->next != NULL && ((token->type == WORD
				&& token->next->type == WORD) || (token->type == SPACEE
				&& token->next->type == SPACEE) || (token->type == REDIRECTION
				&& token->next->type == REDIRECTION)))
	{
		if (*str == NULL)
		{
			temp_str = *str;
			*str = ft_strjoin(&token->value, "");
			free(temp_str);
		}
		temp_str = *str;
		*str = ft_strjoin(*str, &token->next->value);
		free(temp_str);
		token = token->next;
	}
	return (token);
}

int	ft_check_type_diff_wsr(int token_type)
{
	if (token_type != WORD || token_type != SPACEE || token_type != REDIRECTION)
		return (1);
	return (0);
}

int	ft_check_type_is_wsr(int token_type)
{
	if (token_type == WORD || token_type == SPACEE || token_type == REDIRECTION)
		return (1);
	return (0);
}

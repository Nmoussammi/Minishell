/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:40:33 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:37:59 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_tokenize(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp != NULL)
	{
		if (temp->value == ' ')
			temp->type = SPACEE;
		else if (temp->value == 39)
			temp->type = SQUOTE;
		else if (temp->value == '"')
			temp->type = DQUOTE;
		else if (temp->value == '|')
			temp->type = PIPE;
		else if (temp->value == '>' || temp->value == '<')
			temp->type = REDIRECTION;
		else if (temp->value == '$')
			temp->type = DOLLAR;
		else if (ft_isprint(temp->value))
			temp->type = WORD;
		temp = temp->next;
	}
}

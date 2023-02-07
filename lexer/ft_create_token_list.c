/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:17 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:43:03 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_create_token_list(char	*line)
{
	t_token	*token;
	t_token	*new_token;
	t_token	*temp;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = *line;
	token->name = NULL;
	line++;
	token->next = NULL;
	temp = token;
	while (*line != '\0')
	{
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->value = *line;
		new_token->name = NULL;
		new_token->next = NULL;
		temp->next = new_token;
		temp = temp->next;
		line++;
	}
	return (token);
}

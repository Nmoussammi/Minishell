/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dquotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:51:17 by makacem           #+#    #+#             */
/*   Updated: 2023/01/16 11:16:50 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_check_dquotes(t_token *token_list)
{
	int		count;
	t_token	*token;

	count = 0;
	token = token_list;
	while (token != NULL)
	{
		if (token->type == DQUOTE)
			count++;
		token = token->next;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

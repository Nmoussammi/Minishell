/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:42 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 09:59:41 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_tokens(t_token *token_list)
{
	free(token_list);
	token_list = token_list->next;
	while (token_list != NULL)
	{
		free(token_list->name);
		free(token_list);
		token_list = token_list->next;
	}
}

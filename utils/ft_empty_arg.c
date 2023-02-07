/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:02:00 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 22:33:28 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_for_dq(t_token	*tmp_token);

void	ft_empty_arg(t_token *token_list)
{
	t_token	*tmp_token;

	tmp_token = token_list;
	while (tmp_token != NULL)
	{
		if (tmp_token->next != NULL
			&& tmp_token->type == DQUOTE && tmp_token->next->type == DQUOTE)
			ft_for_dq(tmp_token);
		tmp_token = tmp_token->next;
	}
	tmp_token = token_list;
	while (tmp_token != NULL)
	{
		if (tmp_token->next != NULL
			&& tmp_token->type == SQUOTE && tmp_token->next->type == SQUOTE)
			ft_for_dq(tmp_token);
		tmp_token = tmp_token->next;
	}
}

void	ft_for_dq(t_token	*tmp_token)
{
	t_token	*frst_dq;
	t_token	*scd_dq;

	frst_dq = tmp_token;
	frst_dq->type = WORD;
	free(frst_dq->name);
	tmp_token->name = ft_strjoin("", "");
	scd_dq = tmp_token->next;
	free(scd_dq->name);
	tmp_token->next = scd_dq->next;
	free(scd_dq);
}

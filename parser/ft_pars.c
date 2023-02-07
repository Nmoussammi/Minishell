/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:31 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 18:19:29 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_print_token_content(t_token *token_list);
void	ft_print_type(t_token *token_list);

int	ft_pars(t_token *token_list)
{
	if (ft_check_dquotes(token_list) == 1)
		return (1);
	else if (ft_check_squotes(token_list) == 1)
		return (1);
	else if (ft_check_pipes(token_list) == 1)
		return (1);
	else if (ft_check_redirections(token_list) == 1)
		return (1);
	return (0);
}

void	ft_print_token_content(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	temp = temp->next;
	while (temp != NULL)
	{
		printf("'%s' ", temp->name);
		temp = temp->next;
	}
	printf("\n");
}

void	ft_print_type(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			printf("PIPE ");
		else if (temp->type == WORD)
			printf("WORD ");
		else if (temp->type == REDIRECTION)
			printf("REDIRECTION ");
		else if (temp->type == SPACEE)
			printf("SPACE ");
		else if (temp->type == DQUOTE)
			printf("DQUOTE ");
		else if (temp->type == SQUOTE)
			printf("SQUOTE ");
		else if (temp->type == DOLLAR)
			printf("DOLLAR ");
		temp = temp->next;
	}
	printf("\n");
}

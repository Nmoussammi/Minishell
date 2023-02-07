/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:16:01 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:43:51 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_treenode	*ft_create_pipe(t_token *token_list);

t_treenode	*ft_pipe_links(t_token *token_list)
{
	int			nbrof_pipes;
	t_treenode	*new_pipe;
	t_treenode	*temp;
	t_treenode	*root;

	root = NULL;
	nbrof_pipes = ft_count_pipes(token_list);
	if (nbrof_pipes != 0)
	{
		root = ft_create_pipe(token_list);
		temp = root;
		nbrof_pipes--;
	}
	while (nbrof_pipes > 0)
	{
		new_pipe = ft_create_pipe(token_list);
		temp->left = new_pipe;
		temp = temp->left;
		nbrof_pipes--;
	}
	return (root);
}

int	ft_count_pipes(t_token *token_list)
{
	int	count;

	count = 0;
	while (token_list != NULL)
	{
		if (token_list->type == PIPE)
			count++;
		token_list = token_list->next;
	}
	return (count);
}

t_treenode	*ft_create_pipe(t_token *token_list)
{
	t_treenode	*root;

	token_list = NULL;
	root = malloc(sizeof(t_treenode));
	root->type = PIPE;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

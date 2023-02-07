/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:59:00 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 22:34:11 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_tree(t_treenode *root)
{
	t_treenode	*left;
	t_treenode	*tmp;

	left = root;
	if (root == NULL)
		return ;
	while (left != NULL)
	{
		if (left->right != NULL )
			free(left->right->cmd);
		free(left->right);
		left = left->left;
	}
	tmp = root;
	free(tmp);
	tmp = tmp->left;
	while (tmp != NULL)
	{
		if (tmp->type == CMD)
			free(tmp->cmd);
		free(tmp);
		tmp = tmp->left;
	}
}

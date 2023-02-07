/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:02:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 20:03:12 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_treenode	*ft_tree(t_token *token_list)
{
	t_treenode	*root;

	root = ft_pipe_links(token_list);
	root = ft_cmd_links(root, token_list);
	return (root);
}

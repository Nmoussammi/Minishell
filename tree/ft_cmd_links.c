/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:26:43 by makacem           #+#    #+#             */
/*   Updated: 2023/01/14 22:02:58 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_treenode	*ft_cmd_links(t_treenode *root, t_token *token_list)
{
	int			nbr_of_pipes;
	t_treenode	*temp;
	t_treenode	*new_cmd;

	nbr_of_pipes = ft_count_pipes(token_list);
	if (root == NULL)
		root = ft_create_cmd(token_list);
	else if (root != NULL)
	{
		temp = root;
		while (nbr_of_pipes > 0)
		{
			new_cmd = ft_create_cmd(token_list);
			token_list = ft_skip_tonextpipe(token_list);
			temp->right = new_cmd;
			if (nbr_of_pipes == 1)
			{
				new_cmd = ft_create_cmd(token_list);
				temp->left = new_cmd;
			}
			temp = temp->left;
			nbr_of_pipes--;
		}
	}
	return (root);
}

t_token	*ft_skip_tonextpipe(t_token *token_list)
{
	while (token_list->type != PIPE)
		token_list = token_list->next;
	token_list = token_list->next;
	return (token_list);
}

t_treenode	*ft_create_cmd(t_token *token_list)
{
	t_treenode	*root;

	root = malloc(sizeof(t_treenode));
	root->type = CMD;
	root->stdin_fd = ft_fdin(token_list);
	root->stdout_fd = ft_fdout(token_list);
	root->cmd = ft_creat_args(token_list);
	root->nb_cmd = ft_count_cmds(root->cmd);
	root->left = NULL;
	root->right = NULL;
	return (root);
}

char	**ft_creat_args(t_token *token)
{
	char		**args;
	char		**cmd;
	int			nbr_words;

	nbr_words = ft_count_words(token);
	cmd = malloc((nbr_words + 1) * sizeof(char **));
	args = cmd;
	while (token != NULL)
	{
		if (token->type == WORD || token->type == REDIRECTION)
		{
			*args = token->name;
			args++;
		}
		else if (token->type == PIPE)
		{
			*args = NULL;
			return (cmd);
		}
		token = token->next;
	}
	*args = NULL;
	return (cmd);
}

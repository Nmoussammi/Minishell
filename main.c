/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 00:41:40 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_utils2(char *line, t_token *token_list)
{
	ft_pars_error();
	free(line);
	ft_free_tokens(token_list);
}

void	ft_free1(char *line, t_token *token_list, t_treenode *root)
{
	free(line);
	ft_free_tokens(token_list);
	ft_free_tree(root);
}

char	**initialize(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	g_global.sig = 0;
	g_global.sig_cat = 0;
	env = ft_create_new_env(env);
	return (env);
}

void	main_utils4(t_token *token_list, char **env)
{
	ft_empty_arg(token_list);
	ft_expand(token_list, env);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_token		*token_list;
	t_treenode	*root;

	env = initialize(argc, argv, env);
	while (1)
	{
		handling_sig();
		line = readline("minishell$ ");
		if (main_utils(line) == 1)
			continue ;
		token_list = ft_lex(line);
		if (ft_pars(token_list) == 1)
			main_utils2(line, token_list);
		else
		{
			main_utils4(token_list, env);
			root = ft_tree(token_list->next);
			env = ft_execute(root, env);
			ft_free1(line, token_list, root);
		}
	}
	ft_free_env(env);
	return (0);
}

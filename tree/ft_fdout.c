/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:02 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_redirect_output(t_token *redirec_token);
int		ft_append_output(t_token *redirec_token);
t_token	*ft_redictionfor_output(t_token *tokne_list);

int	ft_fdout(t_token *token_list)
{
	int		fd_out;
	t_token	*redirection;

	fd_out = 0;
	redirection = token_list;
	while (redirection != NULL)
	{
		redirection = ft_redictionfor_output(token_list);
		if (redirection != NULL)
		{
			if (ft_strncmp(redirection->name, ">", 2) == 0)
				fd_out = ft_redirect_output(redirection);
			else if (ft_strncmp(redirection->name, ">>", 2) == 0)
				fd_out = ft_append_output(redirection);
		}
	}
	return (fd_out);
}

int	ft_redirect_output(t_token *redirec_token)
{
	int		fd;
	char	*file_name;

	fd = 0;
	while (redirec_token != NULL && redirec_token->type != WORD && \
	redirec_token->type != 15)
	{
		redirec_token->type = SPACEE;
		redirec_token = redirec_token->next;
	}
	if (redirec_token->type == 15)
	{
		ft_printf("minishell: $%s: ambiguous redirect\n", redirec_token->name);
		g_global.exit_status = 1;
		return (-1);
	}
	file_name = redirec_token->name;
	redirec_token->type = SPACEE;
	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_printf("minishell: %s: %s\n", file_name, strerror(errno));
		g_global.exit_status = 1;
	}
	return (fd);
}

int	ft_append_output(t_token *redirec_token)
{
	int		fd;
	char	*file_name;

	fd = 0;
	while (redirec_token != NULL && redirec_token->type != WORD && \
	redirec_token->type != 15)
	{
		redirec_token->type = SPACEE;
		redirec_token = redirec_token->next;
	}
	if (redirec_token->type == 15)
	{
		ft_printf("minishell: $%s: ambiguous redirect\n", redirec_token->name);
		g_global.exit_status = 1;
		return (-1);
	}
	file_name = redirec_token->name;
	redirec_token->type = SPACEE;
	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_printf("minishell: %s: %s\n", file_name, strerror(errno));
		g_global.exit_status = 1;
	}
	return (fd);
}

t_token	*ft_redictionfor_output(t_token *tokne_list)
{
	t_token	*token;

	token = tokne_list;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type == REDIRECTION && (ft_strncmp(token->name, ">", 2) == 0 \
		|| ft_strncmp(token->name, ">>", 2) == 0))
			return (token);
		token = token->next;
	}
	return (NULL);
}

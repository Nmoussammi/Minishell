/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:59:14 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc(char *delimiter, char *linef, int fd, t_token *token);

int	ft_fdin(t_token *token_list)
{
	int		fd_in;
	t_token	*redirection;

	fd_in = 0;
	redirection = token_list;
	while (redirection != NULL)
	{
		redirection = ft_redictionfor_input(token_list);
		if (redirection != NULL)
		{
			if (ft_strncmp(redirection->name, "<", 2) == 0)
				fd_in = ft_redirect_input(redirection);
			else if (ft_strncmp(redirection->name, "<<", 2) == 0)
				fd_in = ft_heredoc_input(redirection);
		}
	}
	return (fd_in);
}

int	ft_redirect_input(t_token *redirec_token)
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
	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_printf("minishell: %s: %s\n", file_name, strerror(errno));
		g_global.exit_status = 1;
	}
	return (fd);
}

int	ft_heredoc_input(t_token *redirec_token)
{
	int		fd;
	char	*delimiter;
	char	*linef;

	fd = 0;
	g_global.sig = 1;
	redirec_token->type = SPACEE;
	while (redirec_token != NULL && redirec_token->type != WORD && \
	redirec_token->type != 15)
	{
		redirec_token->type = SPACEE;
		redirec_token = redirec_token->next;
	}
	delimiter = redirec_token->name;
	redirec_token->type = SPACEE;
	fd = open("/tmp/heredoc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	linef = "";
	delimiter = ft_strjoin(redirec_token->name, "\n");
	ft_heredoc(delimiter, linef, fd, redirec_token);
	g_global.exit_heredoc = 1;
	close(fd);
	fd = open("/tmp/heredoc", O_RDONLY, 0644);
	return (fd);
}

t_token	*ft_redictionfor_input(t_token *tokne_list)
{
	t_token	*token;

	token = tokne_list;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type == REDIRECTION
			&& (ft_strncmp(token->name, "<", 2) == 0 \
			|| ft_strncmp(token->name, "<<", 2) == 0))
			return (token);
		token = token->next;
	}
	return (NULL);
}

void	ft_heredoc(char *delimiter, char *linef, int fd, t_token *token)
{
	char	*line;

	if (token->next != NULL
		&& (ft_strncmp(token->next->name, "\"", 1) == 0
			|| ft_strncmp(token->next->name, "'", 1) == 0))
	token->next->type = SPACEE;
	while (ft_strcmp(linef, delimiter) != 0 && g_global.exit_heredoc == 1)
	{
		line = readline("> ");
		if (!(line))
			break ;
		else
		{
			linef = ft_strjoin(line, "\n");
			free(line);
		}
		if (ft_strcmp(linef, delimiter) != 0)
		{
			ft_putstr_fd(linef, fd);
			free(linef);
		}
		else
			free(linef);
	}
	free(delimiter);
}

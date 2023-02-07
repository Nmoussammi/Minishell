/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:21:25 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 01:59:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_token	*ft_dont_exppend(t_token *token_list);
t_token	*ft_tryto_exppend(t_token *token_list, char **env);

void	ft_expand(t_token *token_list, char **env)
{
	char	*p_exit_status;

	while (token_list != NULL)
	{
		if (token_list->type == DOLLAR)
		{
			token_list->type = SPACEE;
			if (token_list->next == NULL || token_list->next->type == SPACEE \
			|| token_list->next->type == DOLLAR)
				token_list->type = WORD;
			else if (ft_strncmp(token_list->next->name, "?", 1) == 0)
			{
				p_exit_status = ft_itoa(g_global.exit_status);
				free(token_list->next->name);
				token_list->next->name = ft_strjoin(p_exit_status, "");
				free(p_exit_status);
			}
			else if (token_list->next->type == WORD)
				ft_tryto_exppend(token_list, env);
		}
		else if (token_list->type == REDIRECTION \
			&& ft_strncmp(token_list->name, "<<", 2) == 0)
			token_list = ft_dont_exppend(token_list);
		token_list = token_list->next;
	}
}

t_token	*ft_tryto_exppend(t_token *token_list, char **env)
{
	char	*var;
	char	*content;
	char	*allocated_cont;
	int		content_len;

	var = token_list->next->name;
	content = ft_getenv(env, var);
	if (content == NULL)
	{
		token_list->next->type = 15;
		content = token_list->next->name;
	}
	content_len = ft_strlen(content) + 1;
	allocated_cont = malloc(content_len * sizeof(char));
	ft_strlcpy(allocated_cont, content, content_len);
	free(token_list->next->name);
	token_list->next->name = allocated_cont;
	return (token_list);
}

t_token	*ft_dont_exppend(t_token *token_list)
{
	char	*var;

	while (token_list->next != NULL)
	{
		if (token_list->type == DOLLAR && (token_list->next == NULL
				|| token_list->next->type == DQUOTE
				|| token_list->next->type == SQUOTE))
		{
			token_list->type = WORD;
			return (token_list);
		}
		else if (token_list->type == DOLLAR && token_list->next->type == WORD)
		{
			token_list->type = SPACEE;
			var = token_list->next->name;
			token_list->next->name = ft_strjoin("$", var);
			free(var);
			return (token_list);
		}
		token_list = token_list->next;
	}
	token_list->type = WORD;
	return (token_list);
}

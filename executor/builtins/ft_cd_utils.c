/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:42:14 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/18 02:09:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	home_utils1(char *tmp_pwd)
{
	free(tmp_pwd);
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	g_global.exit_status = 1;
}

void	home_utils2(char *tmp_pwd)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free(tmp_pwd);
	g_global.exit_status = 1;
}

char	**home_utils3(char *home, char *tmp_pwd, char **pwd, char **env)
{
	char	**oldpwd;
	char	*new_pwd;

	if (!pwd)
	{
		new_pwd = ft_strjoin("PWD=", tmp_pwd);
		env = ft_add_var(new_pwd, env);
		free(new_pwd);
		oldpwd = ft_search_val(env, "OLDPWD=");
		free(*oldpwd);
		*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
		free(tmp_pwd);
		g_global.exit_status = 0;
		return (env);
	}
	else
	{
		free(*pwd);
		*pwd = ft_strjoin("PWD=", home);
		oldpwd = ft_search_val(env, "OLDPWD=");
		free(*oldpwd);
		*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
		free(tmp_pwd);
	}
	return (env);
}

void	print_msg(char *cwd)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free(cwd);
	g_global.exit_status = 1;
}

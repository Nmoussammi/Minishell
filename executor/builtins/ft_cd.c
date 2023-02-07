/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/17 21:42:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_home(char *cwd, char **env)
{
	char	*home;
	char	**pwd;
	char	*tmp_pwd;

	home = ft_getenv(env, "HOME");
	tmp_pwd = getcwd(NULL, 0);
	if (!home)
	{
		home_utils1(tmp_pwd);
		free(cwd);
		return (env);
	}
	else if (chdir(home) == -1)
		return (home_utils2(tmp_pwd), env);
	else
	{
		pwd = ft_search_val(env, "PWD=");
		env = home_utils3(home, tmp_pwd, pwd, env);
	}
	g_global.exit_status = 0;
	free(cwd);
	return (env);
}

char	**ft_old_pwd(char **env)
{
	char	**old_pwd;
	char	*pwd;

	pwd = ft_getenv(env, "PWD=");
	old_pwd = ft_search_val(env, "OLDPWD=");
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
		free(*old_pwd);
		*old_pwd = ft_strjoin("OLDPWD=", pwd);
		free(pwd);
		return (env);
	}
	if (!old_pwd)
		env = ft_add_var("OLDPWD=", env);
	free(*old_pwd);
	*old_pwd = ft_strjoin("OLDPWD=", pwd);
	return (env);
}

char	**ft_new_pwd(char **env)
{
	char	**pwd;
	char	*new_pwd;
	char	*tmp_pwd;

	pwd = ft_search_val(env, "PWD");
	if (!pwd)
	{
		tmp_pwd = getcwd(NULL, 0);
		new_pwd = ft_strjoin("PWD=", tmp_pwd);
		env = ft_add_var(new_pwd, env);
		free(new_pwd);
		free(tmp_pwd);
		return (env);
	}
	else
	{
		free(*pwd);
		tmp_pwd = getcwd(NULL, 0);
		*pwd = ft_strjoin("PWD=", tmp_pwd);
		free(tmp_pwd);
	}
	return (env);
}

char	**ft_cd_point(char *cwd, char **env)
{
	ft_putstr_fd("cd: error retrieving current directory: \
	getcwd: cannot access parent directories: No such file or directory\n", 2);
	g_global.exit_status = 0;
	free(cwd);
	return (env);
}

char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*old_pwd;
	char	*cwd;

	old_pwd = ft_getenv(env, "OLDPWD");
	cwd = getcwd(NULL, 0);
	if (!old_pwd)
		env = ft_add_var("OLDPWD", env);
	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(cmd[1], "~") == 0 \
	|| ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0)))
		return (ft_home(cwd, env), env);
	else if (cwd == NULL && ft_strcmp(cmd[1], ".") == 0)
		return (ft_cd_point(cwd, env), env);
	else
	{
		if (chdir(cmd[1]) == -1)
			return (print_msg(cwd), env);
		else
		{
			env = ft_old_pwd(env);
			env = ft_new_pwd(env);
			g_global.exit_status = 0;
			free(cwd);
			return (env);
		}
	}
}

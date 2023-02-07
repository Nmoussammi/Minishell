/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:34:37 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 21:42:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		ft_cmpin_env(char	**env, char *var);
char	**ft_populate_unset(char **new_env, char **old_env, char *var);

char	**ft_unset(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1)
	{
		g_global.exit_status = 0;
		return (env);
	}
	else if (n_cmd > 1)
	{
		arg = cmd;
		arg++;
		while (*arg != NULL)
		{
			if (ft_cmpin_env(env, *arg) == 1)
				env = ft_remove_var(env, *arg);
			arg++;
		}
	}
	g_global.exit_status = 0;
	return (env);
}

char	**ft_populate_unset(char **new_env, char **old_env, char *var)
{
	char	*new_array;
	char	**temp;
	char	*temp_arr;
	int		var_len;

	temp = new_env;
	while (*old_env != '\0')
	{
		temp_arr = var;
		var_len = 0;
		while (*temp_arr != '\0' && *temp_arr != '=')
		{
			var_len++;
			temp_arr++;
		}
		if (strncmp(*old_env, var, var_len) != 0)
		{
			new_array = ft_strdup(*old_env);
			*temp = new_array;
			temp++;
		}
		old_env++;
	}
	*temp = NULL;
	return (new_env);
}

char	**ft_remove_var(char	**env, char *var)
{
	char	**new_env;

	new_env = malloc(ft_count_env_var(env) * sizeof(char **));
	new_env = ft_populate_unset(new_env, env, var);
	ft_free_env(env);
	return (new_env);
}

int	ft_cmpin_env(char	**env, char *var)
{
	char	**arr;
	char	*temp;
	int		var_len;

	arr = env;
	while (*arr != '\0')
	{
		temp = *arr;
		var_len = 0;
		while (*temp != '\0' && *temp != '=')
		{
			var_len++;
			temp++;
		}
		if (ft_strlen(var) == var_len)
		{
			if (ft_strncmp(*arr, var, var_len) == 0)
				return (1);
		}
		arr++;
	}
	return (0);
}

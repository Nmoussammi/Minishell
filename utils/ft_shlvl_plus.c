/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:57 by makacem           #+#    #+#             */
/*   Updated: 2023/01/14 13:17:08 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_shlvl_plus(char **env)
{
	int		shlvl_i;
	char	**old_val;
	char	*shlvl;
	char	*temp;

	shlvl = ft_getenv(env, "SHLVL");
	shlvl_i = ft_atoi(shlvl);
	shlvl_i++;
	shlvl = ft_itoa(shlvl_i);
	temp = shlvl;
	shlvl = ft_strjoin("SHLVL=", shlvl);
	old_val = ft_search_val(env, shlvl);
	free(*old_val);
	*old_val = shlvl;
	free(temp);
	return (env);
}

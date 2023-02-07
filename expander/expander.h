/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:26:56 by makacem           #+#    #+#             */
/*   Updated: 2023/01/13 18:47:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H

# define EXPANDER_H

# include "../parser/parser.h"
# include "../minishell.h"

void	ft_expand(t_token *token_list, char **env);
char	*ft_getenv(char	**env, char *var);

#endif
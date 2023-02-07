/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:18:30 by makacem           #+#    #+#             */
/*   Updated: 2022/12/22 21:02:57 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "../lexer/lexer.h"

int	ft_pars(t_token *token_list);
int	ft_pars_error(void);
int	ft_check_squotes(t_token *token_list);
int	ft_check_dquotes(t_token *token_list);
int	ft_check_pipes(t_token *token_list);
int	ft_check_redirections(t_token *token_list);

#endif

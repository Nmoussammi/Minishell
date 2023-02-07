/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:31:56 by makacem           #+#    #+#             */
/*   Updated: 2023/01/16 14:14:01 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# define SPACEE 0
# define PIPE 1
# define WORD 2
# define REDIRECTION 3
# define DQUOTE 4
# define SQUOTE 5
# define DOLLAR 6 

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct token
{
	char			value;
	int				type;
	char			*name;
	struct token	*next;

}	t_token;

t_token	*ft_lex(char	*line);
t_token	*ft_create_token_list(char	*line);
void	ft_tokenize(t_token *token);
void	ft_wordnize_sq(t_token *token);
void	ft_wordnize_dq(t_token *token);
t_token	*ft_grp_tokens(t_token *token);
void	ft_grp_two_words(t_token *token);

#endif
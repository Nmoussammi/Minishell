# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:29:08 by makacem           #+#    #+#              #
#    Updated: 2023/01/18 00:45:54 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Wextra -Werror
HEADER = minishell.h
LFLAGS = -L /Users/makacem/homebrew/Cellar/readline/8.2.1/lib
IFLAGS = -I /Users/makacem/homebrew/Cellar/readline/8.2.1/include

SRC = main.c \
	main_utils.c \
	ft_signalhandler.c \
	lexer/ft_lex.c \
	lexer/ft_create_token_list.c \
	lexer/ft_tokenize.c \
	lexer/ft_wordnize.c \
	lexer/ft_grp_tokens.c \
	parser/ft_pars.c \
	parser/ft_check_squotes.c \
	parser/ft_check_dquotes.c \
	parser/ft_check_pipes.c \
	parser/ft_check_redirections.c \
	expander/ft_expand.c \
	tree/ft_tree.c \
	tree/ft_pipe_links.c \
	tree/ft_cmd_links.c \
	tree/ft_fdout.c \
	tree/ft_fdin.c \
	tree/ft_count.c \
	utils/ft_strcmp.c \
	utils/ft_lower.c \
	utils/ft_count_env_var.c \
	utils/ft_create_new_env.c \
	utils/ft_free_env.c \
	utils/ft_free_tokens.c \
	utils/ft_getenv.c \
	utils/ft_populate.c \
	utils/ft_shlvl_plus.c \
	utils/ft_empty_arg.c \
	utils/ft_free_tree.c \
	executor/ft_execute.c \
	executor/exec_cmd.c \
	executor/pipe.c \
	executor/execve.c \
	executor/exec_cmd_utils.c \
	executor/builtins/ft_env.c \
	executor/builtins/ft_export.c \
	executor/builtins/ft_echo.c \
	executor/builtins/ft_pwd.c \
	executor/builtins/ft_cd.c \
	executor/builtins/ft_cd_utils.c \
	executor/builtins/ft_unset.c \
	executor/builtins/ft_exit.c \
	executor/builtins/export_utils.c \
	executor/ft_dup_open.c \
	executor/ft_dup_close.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C ./libft
	$(CC) $(FLAGS)  $(OBJ) -o $(NAME) -lreadline -lncurses $(LFLAGS) libft/libft.a

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all
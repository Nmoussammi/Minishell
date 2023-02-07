/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:01 by makacem           #+#    #+#             */
/*   Updated: 2023/01/18 02:39:10 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./lexer/lexer.h"
# include "./parser/parser.h"
# include "./expander/expander.h"
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

# define CMD 7
# define PIPE 1

typedef struct s_global
{
	int	exit_heredoc;
	int	sig;
	int	sig_cat;
	int	exit_status;
}								t_global;

t_global	g_global;

typedef struct t_treenode {
	int					type;
	char				**cmd;
	int					nb_cmd;
	int					stdin_fd;
	int					stdout_fd;
	int					temp_fdin;
	int					temp_fdout;
	struct t_treenode	*left;
	struct t_treenode	*right;
}	t_treenode;

t_treenode	*ft_tree(t_token *token_list);
t_treenode	*ft_pipe_links(t_token *token_list);
int			ft_count_pipes(t_token *token_list);
t_treenode	*ft_cmd_links(t_treenode *root, t_token *token_list);
int			ft_fdout(t_token *token_list);
int			ft_fdin(t_token *token_list);
int			ft_count_words(t_token *token);
int			ft_count_env_var(char	**env);
char		**ft_populate(char **new_env, char **old_env);
void		ft_free_env(char **env);
void		ft_signalhandler(void);
void		ft_heredoc_signals(void);
char		**ft_env(int n_cmd, char **cmd, char **env);
char		**ft_export(int n_cmd, char **cmd, char **env);
char		**ft_unset(int n_cmd, char **cmd, char **env);
char		**ft_echo(int n_cmd, char **cmd, char **env);
char		**ft_pwd(int n_cmd, char **cmd, char **env);
char		**ft_cd(int n_cmd, char **cmd, char **env);
int			check_alphabet(char *str, char alphabet);
char		**ft_add_var(char *var, char **env);
char		**ft_search_val(char	**env, char *var);
void		ft_print_env(char **env);
char		**ft_sort_env(char **env);
int			ft_search_env(char	**env, char *var);
char		**ft_remove_var(char	**env, char *var);
int			ft_search_env(char	**env, char *var);
char		**ft_home(char *cwd, char **env);
void		execute_left(int *fd, t_treenode *left, char **env);
void		execute_right(int *fd, t_treenode *right, char **env);
char		**ft_execute(t_treenode *root, char **env);
int			path_exist(char *path);
char		**path(t_treenode *root, char **env);
int			exec_file(t_treenode *root, char *path, char **env);
void		find_and_exec(t_treenode *root, char **str, char **env);
void		ft_exec_cmd(t_treenode *root, char **env);
char		**ft_execute_rec(t_treenode *root, char **env);
char		**execution_cmd(t_treenode *root, char **env);
void		ft_pipe(t_treenode *root, char **env);
int			ft_strcmp(char *s1, char *s2);
void		ft_to_lower(char *str);
char		**ft_shlvl_plus(char **env);
int			ft_count_env_var(char	**env);
char		*ft_getenv(char	**env, char *var);
void		ft_free_tokens(t_token *token_list);
char		**ft_create_new_env(char **old_env);
int			ft_cmpin_env(char	**env, char *var);
char		**ft_populate(char **new_env, char **old_env);
int			ft_dupin_open(int fd_stdin);
int			ft_dupout_open(int fd_stdout);
void		ft_dupin_close(int fd_stdin, int temp_fdin);
void		ft_dupout_close(int fd_stdout, int temp_fdout);
char		**ft_exit(int n_cmd, char **cmd, char **env);
char		**ft_jointo_old(char **env, char *arg);
char		**ft_search_val(char **env, char *var);
char		**ft_add_var(char *var, char **env);
void		ft_print_type(t_token *token_list);
void		ft_print_token_content(t_token *token_list);
t_token		*ft_redictionfor_input(t_token *tokne_list);
int			ft_redirect_input(t_token *redirec_token);
int			ft_heredoc_input(t_token *redirec_token);
void		ft_print_type(t_token *token_list);
void		ft_print_token_content(t_token *token_list);
t_treenode	*ft_create_cmd(t_token *token_list);
char		**ft_creat_args(t_token *token);
t_token		*ft_skip_tonextpipe(t_token *token_list);
int			ft_pars_export(char *arg);
char		**ft_jointo_old(char **env, char *arg);
int			ft_count_cmds(char	**cmd);
int			ft_count_words(t_token *token);
void		handling_sig(void);
void		handler(int sig);
int			ft_putchar22(int c);
void		home_utils1(char *tmp_pwd);
void		home_utils2(char *tmp_pwd);
char		**home_utils3(char *home, char *tmp_pwd, char **pwd, char **env);
void		print_msg(char *cwd);
char		**ft_cd_point(char *cwd, char **env);
void		ft_print(t_treenode *root, char *cmd, char *tmp);
void		ft_free_tree(t_treenode *root);
void		ft_empty_arg(t_token *token_list);
int			ft_putchar22(int c);
int			event(void);
int			ft_pars_error(void);
int			main_utils(char *line);
void		check_signal(void);
#endif
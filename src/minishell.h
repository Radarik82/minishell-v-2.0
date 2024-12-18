/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:16:32 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/18 13:34:16 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <limits.h>
# include <stdlib.h>
# define READLINE_LIBRARY
# include "../readline/include/readline.h"
# include "../readline/include/history.h"
# include "../readline/include/rlstdc.h"

# include "../libft/libft.h"

// COLORS
# define GREEN	"\033[0;32m"
# define RED	"\033[1;31m"
# define GREY	"\033[0;90m"
# define CYAN	"\033[1;96m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

# define PROMPT "minishell$ "

typedef enum e_token_type
{
	T_WORD = 1,
	T_PIPE,
	T_RED_INP,
	T_RED_OUT,
	T_DELIM,
	T_APPEND,
	T_NEWLINE,
}			t_token_type;

/*
typedef struct s_err
{
	int		code;
	int		flag1;
	int		flag2;
}				t_err;

typedef enum s_dir_type
{
	DIR_IN,
	DIR_OUT,
	DIR_DELIM,
	DIR_APPEND
}			t_dir_type;

typedef struct	s_token
{
	t_token_type	type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct	s_envlst
{
	char 			*name;
	char			*value;
	int 			hidden;
	struct s_envlst	*next;
	// struct s_envlst	*prev;
}				t_envlst;

typedef struct	s_dir
{
	t_dir_type		type;
	char 			*content;
	int 			fd;
	struct	s_dir	*prev;
	struct	s_dir	*next;
}				t_dir;

typedef struct s_token
{
	t_token_type		type;
	char				*word;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;
*/

// list of pipes
typedef struct s_pipe_list
{
	int					fd[2];
	struct s_pipe_list	*next;
	struct s_pipe_list	*prev;
}				t_pipe_list;

// ENV from input or default
typedef struct s_envlst
{
	char			*var_name;
	char			*var_value;
	struct s_envir	*next;
	struct s_envir	*prev;
}				t_envlst;

// tokens from input
typedef struct s_token
{
	t_token_type		type;
	char				*word;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;


typedef struct s_redir
{
	t_token			*redir_token;
	t_token			*redir_word;
	struct s_redir	*next;
}				t_redir;

// list of cmd to execute
typedef struct s_cmd_list
{
	char				*value;
	char				**args_array;
	t_redir				*redir_list;
	t_redir				*in;
	t_redir				*out;
	int					fd_in;
	int					redir_status;
	struct s_cmd_list	*next;
	struct s_cmd_list	*prev;
}				t_cmd_list;

// general data vars 
typedef struct	s_data
{
	char			*input_minishell; // 
	char			**path;
	int				input_argc;
	char			**input_argv;
	char			*input_line;
	int				exiterrorcode; // cover as much as can
	int				errorflag;
	int				isseparator;
	char			**envp;
	char			**env_copy;
	int				stdin;
	int				stdout;

	t_cmd_list		*list;
	struct s_token	*token_list;
	t_token			*tokens;
	t_token			*current_token;
	t_token			*token_proc; //??

	t_envlst	*envlst;
	t_envlst	*explst;
}				t_data;

//extern	t_data  *data;

char	*my_readline(void);

// token create
void	cut_to_token(t_data *data);
t_token	*token_process(char *line, t_data *data);
void	ft_skip_spaces(char **line);
t_token	*set_new_token(char *str, t_token_type type);
void	token_lstaddback(t_token **lst, t_token *new_token);
void	if_in_quotes(t_data *data);

void	env_to_minishell(t_data *data);
int		this_token_prec(t_token *token);
int		this_token_redir(t_token *token);
int		this_token_binop(t_token *token);
void	token_error_check(t_token *lst, t_data *data);
void	next_token(t_token *lst);

void	minishell_cycle(t_data *data);
void	init_minishell_struct(char **envp, t_data **data);
int		append_identifier(char **line_ptr, t_data *data);

bool	skip_quotes(char *line, int *i);
int		isseparator(char *s);

void	what_separator(char **line, t_data *data);
void	append_sep_type(t_token_type type, char **line_ptr, t_data *data);
void	clear_token_list(t_token **lst);
void	message_quotes_error(char linei);

void	print_dlinked_list(t_token *list);
int		if_empty_line(t_data *data);
t_envlst	*ft_envlstlast(t_envlst *lst);
void		ft_envlstadd_back(t_envlst **lst, t_envlst *new);
t_envlst	*ft_envlstnew(char *name, char *value, int is_shlvl);
t_envlst	*crt_envlst(char **envp);
void		print_lst(t_envlst *envlst);
void		ft_free_envlst(t_envlst **lst);
char		*find_env_value(char *name, t_envlst *envlst);
void		unset_env_name_value(char *name, t_envlst *envlst);
void		set_env_name_value(char *name, char *value, t_envlst *envlst);
int			get_pwd(char **args);

#endif

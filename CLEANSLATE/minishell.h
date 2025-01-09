/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:41:59 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/09 10:36:02 by ariazano         ###   ########.fr       */
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

typedef struct	s_data
{
	char	*input_line;
	char	*promt_line;
	char	*input_minishell;
	int		exiterrorcode;
	int		exit;
	int		in;
	int		out;
	int		fdin;
	int		fdout;
	
	struct s_token	*token_list;
	
	//t_envir
	
	t_token	*token_proc;
}				t_data;

typedef struct s_token
{
	t_token_type		type;
	char				*word;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;



// line_utils.c
// line utils
void	check_empty_line(t_data *data); // checks if line empty, add to history if not


// token.c
// tokenization
void		cut_to_token(t_data *data);
t_token		*token_process(char *line, t_data *data);


// token_utils.c
void	ft_skip_spaces(char **line);


// init_data.c
void	init_minishell_struct(char **envp, t_data **data);
void	**create_envp(void);

// envir.c
void	save_envir(t_data *data, char **env_str);

// mini_loop.c
void	minishell_cycle(t_data *data);

// reset_data.c
void	reset_data(t_data *data);

// token_lst_utils.c
void	free_token(t_token **token);
void	free_all_token(t_token **token);
void	*ft_memset(void *b, int c, size_t len);
t_token *set_new_token(char *str, t_token_type type);
void	token_lstaddback(t_token **lst, t_token *new_token);
void	print_dlinked_list(t_token *list);  // dont forget to remove THIS

// parse.c
void	fix_quotes(t_data *data);
int	in_quotes_token(char *s, int *start);
void	trim_tokens_helper(bool *encounter, int *i, int **end);
char	*trim_tokens(char *input, int start, int *end)


#endif

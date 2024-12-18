/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:58:33 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 01:35:35 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/ft_printf.h"

typedef struct s_process
{
	char		*path;
	char		**args;
	int			pid;
}				t_process;

typedef struct s_pipex
{
	char		*infile;
	char		*outfile;
	int			infile_fd;
	int			outfile_fd;
	int			here_doc;
	char		*limiter;
	int			process_total;
	t_list		*processes;
	int			infile_access;
	int			saved_fd;

}				t_pipex;

void		initiate_pipex(t_pipex *pipex);
int			check_access(char *path);
int			str_compare(char *limiter, char *str);
void		open_files(t_pipex *pipex);
void		close_files(t_pipex *pipex);
void		free_list(t_list *lst);
void		free_pipex(t_pipex *pipex);
void		free_array(char **arr);
t_process	*create_prcs(char *cmd, char **envp);
void		heredoc(char **argv, t_pipex *pipex);
int			execution(char *path, char **args, char **envp, int i);
void		do_pipes(t_pipex *pipex, char **envp, int outfile_fd);
void		parsing(int argc, char **argv, char **envp, t_pipex *pipex);

#endif

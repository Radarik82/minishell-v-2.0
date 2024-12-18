/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:50:28 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 01:54:32 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_heredoc(char **argv, t_pipex *pipex, int fd[2])
{
	char	*tmp_str;

	if (close(fd[0]) == -1 || dup2(fd[1], STDOUT_FILENO) == -1
		|| close(fd[1]) == -1)
		exit(-2);
	while (1)
	{
		ft_putstr_fd("pipex heredoc> ", pipex->saved_fd);
		tmp_str = get_next_line(STDIN_FILENO);
		if (!tmp_str)
			exit (-4);
		if (str_compare(argv[2], tmp_str))
		{
			free(tmp_str);
			exit(0);
		}
		ft_putstr_fd(tmp_str, STDOUT_FILENO);
		free(tmp_str);
	}
}

void	heredoc(char **argv, t_pipex *pipex)
{
	int		fd[2];
	int		pid;
	int		status;

	if (pipe(fd) == -1)
		exit (-2);
	pid = fork();
	if (pid == -1)
		exit(-3);
	if (pid == 0)
		child_heredoc(argv, pipex, fd);
	else
	{
		if (close(fd[1]) == -1 || dup2(fd[0], STDIN_FILENO) == -1
			|| close(fd[0]) == -1)
			exit(-2);
		waitpid(pid, &status, 0);
	}
}

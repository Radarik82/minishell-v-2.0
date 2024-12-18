/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:58:41 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 15:41:52 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_dup( int i, int fd[2])
{
	if (i == STDOUT_FILENO)
	{
		if (close(fd[0]) == -1 || dup2(fd[1], STDOUT_FILENO) == -1
			|| close(fd[1]) == -1)
			return (perror("error pipe redirection"), -2);
	}
	else if (i == -1)
		return (-1);
	else
	{
		if (close(fd[0]) == -1 || dup2(i, STDOUT_FILENO) == -1
			|| close(i) == -1 || close(fd[1]) == -1)
			return (perror("error pipe redirection"), -2);
	}
	return (0);
}

int	execution(char *path, char **args, char **envp, int i)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (perror("error: pipe creation\n"), -1);
	pid = fork();
	if (pid == -1)
		exit (-3);
	if (pid == 0)
	{
		if (child_dup(i, fd) == -1)
			exit(0);
		execve(path, args, envp);
		ft_putstr_fd("pipex: comand not found: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(errno);
	}
	if (close(fd[1]) == -1 || dup2(fd[0], STDIN_FILENO) == -1
		|| close(fd[0]) == -1)
		return (perror("error pipe redirection"), -2);
	return (0);
}

void	pipe_prcs(t_pipex *pipex, char **envp, t_list **tmp)
{
	char	*path;
	char	**args;

	path = ((t_process *)(*tmp)->content)->path;
	args = ((t_process *)(*tmp)->content)->args;
	if ((pipex->infile_access == 0 && pipex->here_doc != 1)
		|| pipex->infile_fd == -1)
	{
		pipex->infile_access = 3;
		execution(path, args, envp, -1);
	}
	else
		execution(path, args, envp, STDOUT_FILENO);
	(*tmp) = (*tmp)->next;
}

void	do_pipes(t_pipex *pipex, char **envp, int outfile_fd)
{
	char	*path;
	char	**args;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = pipex->processes;
	while (i++ < pipex->process_total - 1)
	{
		pipe_prcs(pipex, envp, &tmp);
	}
	path = ((t_process *)tmp->content)->path;
	args = ((t_process *)tmp->content)->args;
	execution(path, args, envp, outfile_fd);
	while (i--)
		wait(NULL);
}

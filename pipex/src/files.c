/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:35:06 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 22:49:57 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile_fd = open(pipex->outfile,
				O_CREAT | O_WRONLY | O_APPEND, 0777);
	else
	{
		if (pipex->infile_access)
		{
			pipex->infile_fd = open(pipex->infile, O_RDONLY, 0777);
			if (pipex->infile_fd != -1)
				dup2(pipex->infile_fd, STDIN_FILENO);
		}
		pipex->outfile_fd = open(pipex->outfile,
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
	}
	if (pipex->outfile_fd < 0 && pipex->infile_access)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(pipex->outfile);
	}
	if (pipex->infile_fd < 0 && pipex->infile_access)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(pipex->infile);
	}
}

void	close_files(t_pipex *pipex)
{
	if (pipex->here_doc)
		close(pipex->outfile_fd);
	else
	{
		if (pipex->infile_access)
			close(pipex->infile_fd);
		close(pipex->outfile_fd);
	}
}

//test

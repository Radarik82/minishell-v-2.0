/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:21:22 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 17:23:42 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.saved_fd = dup(STDOUT_FILENO);
	if (argc < 5)
		return (perror("Not enough args"), 1);
	else if (argc > 5)
		return (perror("Too much args"), 1);
	initiate_pipex(&pipex);
	parsing(argc, argv, envp, &pipex);
	open_files(&pipex);
	do_pipes(&pipex, envp, pipex.outfile_fd);
	free_pipex(&pipex);
	close_files(&pipex);
}

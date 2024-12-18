/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:21:22 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 17:09:11 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.saved_fd = dup(STDOUT_FILENO);
	if (argc < 5)
		return (perror("Not enough args"), 1);
	initiate_pipex(&pipex);
	parsing(argc, argv, envp, &pipex);
	open_files(&pipex);
	if (pipex.here_doc)
	{
		if (argc == 6)
			heredoc(argv, &pipex);
		else
			return (ft_putstr_fd("Not right amount of args\n", 2), 1);
	}
	do_pipes(&pipex, envp, pipex.outfile_fd);
	free_pipex(&pipex);
	close_files(&pipex);
}

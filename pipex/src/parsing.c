/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:33:56 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 01:34:14 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int			i;
	t_list		*new_list;

	i = 1;
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = ft_strdup(argv[++i]);
	}
	else if (check_access(argv[i]))
	{
		pipex->infile = ft_strdup(argv[i]);
		pipex->infile_access = 1;
	}
	while (++i < argc - 1)
	{
		new_list = ft_lstnew((t_process *)create_prcs(argv[i], envp));
		ft_lstadd_back(&pipex->processes, new_list);
		pipex->process_total++;
	}
	pipex->outfile = ft_strdup(argv[argc - 1]);
}

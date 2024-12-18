/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:41:16 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 01:53:14 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_prcs_path(char **paths, t_process *process, char *tmp_cmd)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		process->path = ft_strjoin(paths[i], tmp_cmd);
		if (access(process->path, F_OK) == 0)
			break ;
		free(process->path);
		process->path = NULL;
		i++;
	}
}

t_process	*create_prcs(char *cmd, char **envp)
{
	int			i;
	char		**paths;
	char		*tmp_cmd;
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	if (!process)
		return (perror("error creating process"), NULL);
	process->args = ft_split(cmd, ' ');
	process->pid = 0;
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	tmp_cmd = ft_strjoin("/", process->args[0]);
	check_prcs_path(paths, process, tmp_cmd);
	free_array(paths);
	return (free(tmp_cmd), process);
}

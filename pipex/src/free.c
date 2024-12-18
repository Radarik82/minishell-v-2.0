/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:31:43 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 01:55:12 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(((t_process *)lst->content)->path);
		free_array(((t_process *)lst->content)->args);
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void	free_pipex(t_pipex *pipex)
{
	free(pipex->limiter);
	free(pipex->infile);
	free(pipex->outfile);
	free_list(pipex->processes);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

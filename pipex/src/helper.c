/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:36:28 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/18 00:37:10 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initiate_pipex(t_pipex *pipex)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	pipex->process_total = 0;
	pipex->processes = NULL;
	pipex->infile_access = 0;
}

int	check_access(char *path)
{
	if (access(path, F_OK) == 0)
		return (1);
	perror(path);
	return (0);
}

int	str_compare(char *limiter, char *str)
{
	int		str_len;
	int		lim_len;
	char	*tmp;

	lim_len = ft_strlen(limiter);
	str_len = ft_strlen(str);
	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	tmp[str_len - 1] = '\0';
	if (ft_strncmp(limiter, str, str_len - 1) == 0 && lim_len == str_len - 1)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

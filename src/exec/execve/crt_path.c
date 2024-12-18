/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:48:40 by vgabovs           #+#    #+#             */
/*   Updated: 2024/01/30 15:52:07 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

char	*check_path(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, F_OK) == 0)
			return (free(cmd), free_array(paths), path);
		free(path);
		path = NULL;
		i++;
	}
	return (free(cmd), free_array(paths), NULL);
}

char	*create_path(char *cmd, char **envp)
{
	int		i;
	char	**tmp_paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	tmp_paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	return (check_path(tmp_paths, cmd));
}

int main(int argc, char **argv, char **envp)
{
	char *cmd = create_path(argv[1], envp);
	printf("%s\n", cmd);
	free(cmd);
}

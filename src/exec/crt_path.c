/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:48:40 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/24 19:01:03 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	*create_path(char *cmd, t_envlst *envlst)
{
	int		i;
	char	**tmp_paths;
	char	*all_path;

	// i = 0;
	// while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
	// 	i++;
	all_path = find_env_value("PATH", envlst);
	if (all_path == NULL)
		return (printf("No PATH found"), NULL);
	tmp_paths = ft_split(all_path, ':');
	cmd = ft_strjoin("/", cmd);
	return (check_path(tmp_paths, cmd));
}

//take cmd for example "ls" and returns char * with full path /bin/ls

// int main(int argc, char **argv, char **envp)
// {
// 	t_envlst *envlst = crt_envlst(envp);
// 	char *cmd = create_path(argv[1], envlst);
// 	if (!cmd)
// 	{
// 		ft_free_envlst(&envlst);
// 		return (printf("Command not found\n"), 1);
// 	}
// 	printf("%s\n", cmd);
// 	free(cmd);
// }

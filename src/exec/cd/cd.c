/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:35:15 by vgabovs           #+#    #+#             */
/*   Updated: 2024/02/11 19:34:36 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t n);

int	cd(char *path)//, char **envp)
{
	if (!path || ft_strncmp(path, "--\0", 3) == 0)
	{
		char *home = getenv("HOME");
		if (chdir(home) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(home), 2);
		}
	}
	else if (ft_strncmp(path, "-\0", 2) == 0)
	{
		char *oldpwd = getenv("OLDPWD");
		dprintf(1, "oldpwd:%s\n", oldpwd);
		if (oldpwd == NULL)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set", 2);
			return (2);
		}
		if (chdir(oldpwd) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(oldpwd), 2);
		}
	}
	else if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		return (perror(path), 2);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char cwd[1000];

	// if (getcwd(cwd, sizeof(cwd)) != NULL)
	// 	printf("CWD: %s\n", cwd);
	get_pwd();

	// int i = 0;
	// chdir("a");
	// getcwd(cwd, sizeof(cwd));
	// while (cwd[i] != '\0')
	// {
	// 	write(1, &cwd[i], 1);
	// 	i++;
	// }
	// write(1, "\n", 1);
	// dprintf(1, "\nOLDENV:%s\n", getenv("OLDPWD"));
	cd(argv[1]);//, envp);
	// if (argc == 2)
	// {
	// 	if (chdir(argv[1]) == -1)
	// 		return(dprintf(2, "minishell: cd: %s: ", argv[1]), perror(""), 2);
	// }
	// else
	// 	dprintf(2, "NOT enough args\n");

	// if (getcwd(cwd, sizeof(cwd)) != NULL)
	// 	printf("CWD: %s\n", cwd);
	get_pwd();



	// cd(NULL, envp);
	// if (getcwd(cwd, sizeof(cwd)) != NULL)
	// 	printf("CWD: %s\n", cwd);
}

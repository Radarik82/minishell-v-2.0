/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:35:15 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/24 22:29:44 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*my_getenv(char *name, t_envlst *envlst)
{
	return (find_env_value(name, envlst));
}

void	set_oldpwd(t_envlst *envlst)
{
	char cwd[1000];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("Oldpwd not set\n");
	set_env_name_value("OLDPWD", cwd, envlst);
}

int	cd(char *path, t_envlst *envlst)//, char **envp)
{
	char	*home;
	char	*oldpwd;

	if (!path || ft_strncmp(path, "--\0", 3) == 0)
	{
		home = my_getenv("HOME", envlst);
		set_oldpwd(envlst);
		if (chdir(home) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(home), 1);
		}
	}
	else if (ft_strncmp(path, "-\0", 2) == 0)
	{
		oldpwd = my_getenv("OLDPWD", envlst);
		if (oldpwd == NULL)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 1);
			return (1);
		}
		set_oldpwd(envlst);
		if (chdir(oldpwd) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(oldpwd), 1);
		}
	}
	else
	{
		set_oldpwd(envlst);
		if (chdir(path) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(path), 1);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char cwd[1000];

	t_envlst *a = crt_envlst(envp);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("Start CWD: %s\n", cwd);

	if (argc == 1)
	{
		cd(NULL, a);//, envp);
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("CWD: %s\n", cwd);
	}
	int i = 1;
	while (i < argc)
	{
		cd(argv[i], a);
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s CWD: %s\n", argv[i], cwd);
		i++;
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("After CWD: %s\n", cwd);

}

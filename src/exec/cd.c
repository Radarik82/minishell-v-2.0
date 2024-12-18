/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:35:15 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/25 11:21:03 by vgabovs          ###   ########.fr       */
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
		perror("Oldpwd cannot be set\n");
	set_env_name_value("OLDPWD", cwd, envlst);
	// printf("set_old:%s\n", cwd);				//test print
}

int	cd(char *path, t_envlst *envlst)//, char **envp)
{
	char	*home;
	char	*oldpwd;
	char	*tmp_oldpwd;

	printf("\n");
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
		oldpwd = ft_strdup(my_getenv("OLDPWD", envlst));
		if (oldpwd == NULL)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 1);
			return (free(oldpwd), 1);
		}
		set_oldpwd(envlst);
		if (chdir(oldpwd) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(oldpwd), free(oldpwd), 1);
		}
		free(oldpwd);
	}
	else if (ft_strncmp(path, "-", 1) == 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putchar_fd(path[0], 2);
		ft_putchar_fd(path[1], 2);
		return (ft_putstr_fd(" : invalid option\nminishell cd: usage: NO FLAGS\n", 2), 1);
	}
	else
	{
		tmp_oldpwd = ft_strdup(my_getenv("OLDPWD", envlst));
		set_oldpwd(envlst);
		if (chdir(path) == -1)
		{
			set_env_name_value("OLDPWD", tmp_oldpwd, envlst);
			free(tmp_oldpwd);
			ft_putstr_fd("minishell: cd: ", 2);
			return (perror(path), 1);
		}
		free(tmp_oldpwd);
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

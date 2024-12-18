/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:15:17 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/25 11:41:03 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_pwd(char **args)
{
	char	pwd[1000];

	if (args[1] && args[1][0] == '-')
	{
		if (args[1][1] == '-' && args[1][2] == '-' && args[1][3] != '\0')
			return (printf("minishell: pwd: --: invalid option\npwd: usage: no flags\n"), 1);
		else if (args[1][1] != '\0')
			return (printf("minishell: pwd: -%c: invalid option\npwd: usage: no flags\n", args[1][1]), 1);
	}
	if (getcwd(pwd, sizeof(pwd)) != NULL)
		printf("%s\n", pwd);
	else
		return(perror("PWD MISTAKE\n"), 1);
	return (0);
}

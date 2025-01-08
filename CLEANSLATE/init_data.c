/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:23 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/08 23:39:14 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	init_minishell_struct(char **envp, t_data **data)
{
//	ft_memset(data, 0, sizeof(t_data) + 1);
	(*data) = ft_calloc(1, sizeof(t_data));
	if ((*data) == NULL)
		exit(EXIT_FAILURE);
//	if (*envp == NULL)
//		envp = create_envp();
//	(*data)->envp = envp;
//	(*data)->path = NULL;
	(*data)->in = dup(0);
	(*data)->out = dup(1);
//	(*data)->stdin = -1;
//	(*data)->stdout = -1;
	(*data)->exiterrorcode = 0;
	// cmd redirect list
//	(*data)->list = NULL;
	(*data)->token_list = NULL;
	(*data)->input_line = NULL;
	(*data)->input_minishell = "minishell>> ";
	//(*data)->env_copy = NULL;
	//(*data)->envlst = create_envlst((((*data)->env_copy)));
	//(*data)->explst = create_explst((*data)->env_copy);
//	tcgetattr(STDIN_FILENO, &data->original_term);
//	создание энв
	// save_envir((*data), envp); // napisal bazu
// shell v shell'e
	///incr_shell_lvl(*data);
}


char	**create_envp(void)
{
	char	**envp;

	envp = (char **)malloc(sizeof(char *) * 3);
	envp[0] = ft_strdup(ft_strjoin("PWD=", getcwd(NULL, 0)));
	envp[1] = ft_strdup("SHLVL=1");
	envp[2] = ft_strdup("_=./minishell");
	envp[3] = NULL;
	return (envp);
}

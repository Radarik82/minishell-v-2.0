/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:19:00 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/25 00:23:15 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_envlst_sort(t_envlst **envlst)
{
	t_envlst	*tmp;
	t_envlst	*tmp2;
	char		*tmp_name;
	char		*tmp_value;

	tmp = *envlst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strncmp(tmp->name, tmp2->name, ft_strlen(tmp->name)) > 0)
			{
				tmp_name = tmp->name;
				tmp_value = tmp->value;
				tmp->name = tmp2->name;
				tmp->value = tmp2->value;
				tmp2->name = tmp_name;
				tmp2->value = tmp_value;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void	ft_envlst_export_print(t_envlst *envlst)
{
	t_envlst	*tmp;

	tmp = envlst;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->name, 1);
		if (tmp->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}

int	export(char **args, t_envlst **envlst)
{
	if (!args )//|| !args[1])
	{
		ft_envlst_sort(envlst);
		ft_envlst_export_print(*envlst);
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_envlst	*envlst;
	char		*line;
	char		**args;
	int			status;

	envlst = crt_envlst(envp);
	
	export(args, &envlst);
	ft_free_envlst(&envlst);
	return (status);
}
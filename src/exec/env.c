/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:15:28 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/24 23:16:41 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env(t_envlst *envlst)
{
	t_envlst	*tmp;

	tmp = envlst;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(tmp->value, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	return (0);
}
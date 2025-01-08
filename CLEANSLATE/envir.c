/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:51:49 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/07 10:52:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	save_envir(t_data *data, char **env_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env_str[j])
		j++;
	data->env_array = malloc(sizeof(char *) * (j + 1));
	while (env_str[i])
	{
		data->env_array[i] = ft_strdup(env_str[i]);
		i++;
	}
	data->env_array[i] = NULL;
}
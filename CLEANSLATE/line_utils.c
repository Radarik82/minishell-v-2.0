/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:25:25 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/20 12:25:26 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"

int	if_empty_line(t_data *data)
{
	if (!data->input_line)
	{
		rl_on_new_line();
		rl_redisplay();
//		exit_minishell("Exiting...", 0, data);  // needs to be written
	}
	if (!ft_strlen(data->input_line))
		data->input_line = NULL;
	if (ft_strlen(line) > 0)
		add_history(line);
}


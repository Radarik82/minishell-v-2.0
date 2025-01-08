/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:05:43 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/07 11:07:11 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	reset_data(t_data *data)
{
	if (!data)
		return ;
	free_tokens(&data->token_list);
	free_list(&data->list); // reset cmd list   - napisat'
	ft_strdel(&data->input_line);
}
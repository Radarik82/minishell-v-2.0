/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:04:25 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/09 00:12:45 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"

void	minishell_cycle(t_data *data)
{	
	while (1)
	{
		// signal
		g_signal = 0;
		
		// reset data in struct
		reset_data(data);
		
		// init readline lib
		data->promt_line = readline(PROMPT);
		// check empty and -> history
		check_empty_line(data); // ?????
		if (handle_d(data)) // napisat
			continue ;
		if (ft_strlen(data->input_line) > 0)
			add_history(data->input_line);
		// trimming to tokens
		cut_to_token(data);
		if (!data->tokens)
			continue;

		// lexical analisys and replace

		// quotes

		// init evn and tokens in lists

		// execution

	}
}
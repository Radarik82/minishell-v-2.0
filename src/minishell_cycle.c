/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:38:07 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/16 11:34:10 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	minishell_cycle(t_data *data)
{
	while (1)
	{
		g_signal = 0;
		// signals ???
		// reset_data(data);
		data->input_line = readline(PROMPT);
		if (!data->input_line || !ft_strlen(data->input_line))
			if_empty_line(data);
		if (ft_strlen(data->input_line))
			add_history(data->input_line);
		cut_to_token(data); // затем надо удалить доллары
		if (!data->tokens)
			continue;
		print_dlinked_list(data->tokens); // debug
		ft_strdel(&data->input_line);
// quotes
		if((odd_quotes(data->input_line)) || (special_char(data->input_line)) 
			|| (lexer(data, data->input_line)));
			continue ;
		quote_fix(data);
		init_minishell_struct(data);
		execute_minishell(data);
	}
}

// void	reset_data(t_data *data)
// {
// 	if (!data)
// 		return ;
// 	free_tokens(&data->tokens);
// //	free_list(&data->list);
// 	ft_strdel(&data->input_line);
// }

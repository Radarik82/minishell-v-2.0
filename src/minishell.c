/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:38:04 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/16 11:52:45 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	init_minishell_struct(&data, envp);
	handle_signal();
//	data->input_line = "cat 1 | cat2 & cat 3 $ cat 4 < cat  5 > cat fin";
//	cut_to_token(data);
//	print_dlinked_list(data->tokens);
	minishell_cycle(data);
	// clean everything
	clear_history();
	return (0);
}

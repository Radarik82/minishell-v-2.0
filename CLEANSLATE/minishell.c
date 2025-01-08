/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:41:37 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/08 23:43:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data.exit == 0;
	// init
	init_minishell_struct(envp, &(data));
	

	// loop
	while(data.exit == 0)
	{
		// signal
		
		// parse
		
		minishell_cycle(data);
	}
	// free
	free_all(data);
	return (0);
}
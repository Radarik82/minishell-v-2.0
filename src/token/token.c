/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:16:32 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/20 12:02:48 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	cut_to_token(t_data *data)
{
//	char	*line;

//	line = data->input_line;
	token_process(data->input_line, data);
	data->tokens = data->token_proc;
//	free(data->input_line);
	data->input_line = NULL;

}

t_token	*token_process(char *line, t_data *data)
{
	int		error;

	error = 0;
	data->token_proc = NULL;
	while (*line)
	{
		if (error)
			return ((clear_token_list(&data->token_proc)), NULL);
		if (ft_isspace(*line))
			ft_skip_spaces(&line);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
				 || !ft_strncmp(line, "|", 1))
		{
			what_separator(&line, data);
			error = (!data->isseparator && 1);
		}
		else
			error = (!append_identifier(&line, data) && 1);
	}
	return (data->token_proc);
}

void	message_quotes_error(char linei)
{
	ft_printf("minishell: unexpected EOF while looking "
		"for matching '%c' \n", linei);
//	data->exiterrorcode = 258;
}

void	check_empty_line(t_data *data)
{
	if (!data->input_line)
	{
		rl_on_new_line();
		rl_redisplay();
//		exit_minishell("Exiting...", 0, data);  // needs to be written
	}
	if (!ft_strlen(data->input_line))
	{
		data->input_line = NULL;
		return (1);
	}
	if (ft_strlen(data->input_line))
			add_history(data->input_line);
	return (0);
}
// this is DEV

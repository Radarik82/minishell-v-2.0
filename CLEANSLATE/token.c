/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:07:34 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/09 10:13:38 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	cut_to_token(t_data *data)
{
	data->input_line = trim_input(data->promt_line);
	data->input_line = replace_dollars(data, data->input_line);
	ft_strdel(data->promt_line);
	if ((odd_quote(data->input_line)) || (special_chars(data->input_line)) // dodelat'
		|| (lexical_analysis(data, data->input_line))) // ??
		continue ;
	fix_quotes(data);

	data->tokens = token_process(data->input_line, data);
//	free(data->input_line); //where should we do this
	data->input_line = NULL;

}

char	*replace_dollars(t_data *data, char *str)
{
	int		start;
	char	*result;
	int		i;

	start = 0;
	i = 0;
	result = NULL;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?' && !in_single_quotes(str, i))
		{
			add_str_part(str, i, start, &result);
			i += 2;
			join_result_with_exit(data->exit_status, &result);
			start = i;
		}
		else if (str[i] == '$' && str[i + 1] != ' '
			&& !in_single_quotes(str, i))
			replace_variable(data, &i, &start, &result);
		else
			i++;
	}
	add_str_part(str, i, start, &result);
	free(str);
	return (result);
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



void	ft_skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;
}
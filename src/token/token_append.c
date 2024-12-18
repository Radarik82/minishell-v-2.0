/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:12:44 by ariazano          #+#    #+#             */
/*   Updated: 2024/02/07 13:14:11 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	append_identifier(char **line, t_data *data)
{
	char	*line_copy;
	char	*to_token;
	int		i;
	t_token	*token_tmp;

	line_copy = *line;
	i = 0;
	while (line_copy[i] && !isseparator(line_copy + i))
	{
//		printf ("line copy = %s\n", line_copy);
		if (ft_is_quotes(line_copy[i]))
		{
			printf ("line copy [i] = %c\n", line_copy[i]);
			if (!skip_quotes(line_copy, &i))
				return (message_quotes_error(line_copy[i]), 0);
		}
		else
			i++;
	}
	to_token = ft_substr(line_copy, 0, i);
	if (!to_token)
		return (0);
	token_tmp = set_new_token(to_token, T_ID);
	if (!token_tmp)
		return ((free(to_token), 0));
	*line += i;
	token_lstaddback(&data->token_proc, token_tmp);
	return (1);
}


void	append_sep_type(t_token_type type, char **line_ptr, t_data *data)
{
	t_token	*new_token;

//	ft_printf("ast data = %s\n", data->token_proc->content);
	data->isseparator = 0;
	new_token = set_new_token(NULL, type);
	if (!new_token)
		return ;
	token_lstaddback(&data->token_proc, new_token);
	(*line_ptr)++;
	if (type == T_DELIM || type == T_APPEND || type == T_OR || type == T_AND)
		(*line_ptr)++;
	data->isseparator = 1;
}


void	what_separator(char **line, t_data *data)
{
	if (!ft_strncmp(*line, "<<", 2))
		append_sep_type(T_DELIM, line , data);
	else if (!ft_strncmp(*line, ">>", 2))
		append_sep_type(T_APPEND, line , data);
	else if (!ft_strncmp(*line, "<", 1))
		append_sep_type(T_RED_INP, line , data);
	else if (!ft_strncmp(*line, ">", 1))
	 	append_sep_type(T_RED_OUT, line , data);
//	else if (!ft_strncmp(*line, "$", 1))
//		append_sep_type(T_DOLLAR, line , data);
	else if (!ft_strncmp(*line, "&&", 2))
		append_sep_type(T_AND, line , data);
//	else if (!ft_strncmp(*line, "&", 1))
//		append_sep_type(T_AMPER, line , data);
	else if (!ft_strncmp(*line, "(", 1))
	 	append_sep_type(T_LPAR, line , data);
	else if (!ft_strncmp(*line, ")", 1))
		append_sep_type(T_RPAR, line , data);
	else if (!ft_strncmp(*line, "||", 2))
		append_sep_type(T_OR, line , data);
//	else if (!ft_strncmp(*line, "|", 1))
//		append_sep_type(T_PIPE, line , data);
	else
		append_sep_type(T_PIPE, line , data);
}

int	isseparator(char *s)
{
	if (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t'
		|| *s == '<' || *s == '>' || *s == '|' || *s == '(' || *s == ')')
		return (1);
	return (0);
}


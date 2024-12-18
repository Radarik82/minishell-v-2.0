/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:14:38 by ariazano          #+#    #+#             */
/*   Updated: 2024/02/07 13:35:32 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"


void	ft_skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;
}

bool	skip_quotes(char *line, int *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (true);
	}
	return (false);
}

// void	trim_quotes(t_data *data)
// {
// 	t_token	*tmp;

// 	tmp = data->tokens;
// 	tmp->content

// }

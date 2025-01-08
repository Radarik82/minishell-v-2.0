/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:45:23 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/09 00:17:22 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	fix_quotes(t_data *data)
{
	t_token	*head;
	char	*tmp;
	int		start;
	int		end;

	head = data->token_list;
	tmp = NULL;
	while (data->token_list)
	{
		if (data->token_list->type == T_WORD)
		{
			start = -1;
			while (in_quotes_token(data->token_list->word, &start))
			{
				tmp = trim_tokens(data->token_list->word, start, &end);
				ft_strdel(&data->token_list->word);
				data->token_list->word = ft_strdup(tmp);
				ft_strdel(&tmp);
				start = end;
			}
		}
		data->token_list = data->token_list->next;
	}
	data->token_list = head;
}


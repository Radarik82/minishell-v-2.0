/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:39:37 by ariazano          #+#    #+#             */
/*   Updated: 2024/12/19 12:27:42 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	free_tokens(t_token **begin)
{
	t_token	*tmp;
	t_token	*tmp2;

	if (!begin)
		return ;
	tmp = *begin;
	while (tmp)
	{
		ft_strdel(&tmp->word);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*begin = NULL;
}

void	free_redir_list(t_redir **redir)
{
	t_redir	*tmp;

	tmp = NULL;
	if (!(*redir))
		return ;
	while (*redir)
	{
		tmp = (*redir)->next;
		free(*redir);
		*redir = tmp;
	}
}

void	free_list(t_cmd_list **list)
{
	t_cmd_list	*tmp;

	tmp = NULL;
	if (!(*list))
		return ;
	while ((*list))
	{
		tmp = (*list)->next;
	//	free_2darray((*list)->args_array);
		if ((*list)->redir_list)
		{
			free_redir_list(&((*list)->redir_list));
			free((*list)->redir_list);
		}
		free((*list));
		(*list) = tmp;
	}
}

void	free_pipe(t_pipe_list *pipes)
{
	t_pipe_list	*tmp;

	while (pipes)
	{
		tmp = pipes;
		pipes = pipes->next;
		free(tmp);
	}
}
// need to check everything
void	free_data(t_data *data)
{
	if (!data)
		return ;
	//free_2darray(data->env_array);
	//free_2darray(data->new_env_array);
	free_tokens(&data->token_list);
	//ft_envclear(&data->env_list);
	//ft_envclear(&data->export_list);
	free_list(&data->list);
	ft_strdel(&data->input_line);
	free(data);
	data = NULL;
}

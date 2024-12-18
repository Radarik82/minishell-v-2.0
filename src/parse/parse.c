/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:08:43 by ariazano          #+#    #+#             */
/*   Updated: 2024/01/18 23:11:16 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	parse(t_data *data)
{
	t_tree			*left;
	t_tree			*right;
	int				prec_lvl;
	t_token_type	type;

	data->current_token = data->tokens;
	if (data->current_token->type >= 1 && data->current_token->type <= 4)

	else if (data->current_token->type == 5)
	{
		next_token(data->cur_token);
	}
}

void	next_token(t_token *lst)
{
	lst = lst->next;
}

void	next_tree_node(t_token *tree, t_data *data)
{

}

void	token_error_check(t_token *lst, t_data *data)
{
	t_token	*lst_cpy;

	lst_cpy = lst;
	if (ft_strncmp(lst->contetn))
	if (lst->next->type)
}

void	new_node(t_tree *node)


void	if_in_quotes(t_data *data)
{
	t_token *lst;

	lst = data->current_token;
	while (lst->next != NULL)
	{
		if (lst->content && lst->content == '"')
		{
			if (random iff condition)
			//from test chto to drugoe napisal
		}

	}
}

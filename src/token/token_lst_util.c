/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:10 by ariazano          #+#    #+#             */
/*   Updated: 2024/02/07 13:35:27 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	clear_token_list(t_token **lst)
{
	t_token	*curr_node;
	t_token	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->content);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	token_lstaddback(t_token **lst, t_token *new_token)
{
	t_token	*current_token;

	if (!*lst)
	{
		*lst = new_token;
		return ;
	}
	current_token = *lst;
//	ft_printf("adding current %s\n", current_token->content);
	while (current_token && current_token->next)
		current_token = current_token->next;
	current_token->next = new_token;
	new_token->prev = current_token;
}

t_token *set_new_token(char *str, t_token_type type)
{
	t_token	*new_token;

	new_token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->content = str;
	return (new_token);
}

void	print_dlinked_list(t_token *list)
{
	t_token	*current = list;

	if(list == NULL)
	{
		ft_printf("The list is empty\n");
		return;
	}
	while(current != NULL)
	{
//		ft_printf("inside\n");
		ft_printf("type %d node %s\n", current->type, current->content);
		current = current->next;
	}
}

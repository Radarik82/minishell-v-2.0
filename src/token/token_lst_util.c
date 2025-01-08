/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:10 by ariazano          #+#    #+#             */
/*   Updated: 2025/01/08 00:37:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	free_token(t_token **token)
{
	if (!token)
		return ;
	if (*token)
	{
		free((*token)->data);
		(*token)->data = NULL;
	}
	free(*token);
	*token = NULL;
}

void	free_all_token(t_token **token)
{
	if (!token || !*token)
		return ;
	if ((*token)->next)
		free_all_token(&(*token)->next);
	free_token(token);
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

v
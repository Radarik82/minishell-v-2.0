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

t_tree	*new_tree_node(t_tree_type type)
{
	t_tree	*new_node;

	new_node = (t_tree *) ft_calloc(1, sizeof(t_tree));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	return (new_node);
}
t_dir_type	new_dir_node(t_token_type type, char *value)
{
	t_dir	*new_node;

	new_node = (t_dir *)ft_calloc(1, sizeof (t_dir));
	if (!new_node)
		return (NULL);
	new_node->type = token_t_to_tree_dir_t(type);
	new_node->content = ft_strdup(content);
	if (!new_node->content)
		return (free(new_node), NULL);
	return (new_node);
}

void	addback_dir_node(t_dir **lst, t_dir *node)
{
	t_dir	*current_node;

	if (!lst)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node && current_node->next)
		current_node = current_node->next;
	current_node->next = new;
}
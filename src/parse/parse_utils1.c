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

// might need T_PIPE T_OR T_AND instead of numbers
int	this_token_binop(t_token *token)
{
	if (!token->type)
		return (0);
	if (token->type == 1 || token->type == 2 || token->type == 3)
		return (1);
	return (0);
}

int	this_token_redir(t_token *token)
{
	if (!token->type)
		return (0);
	if (token->type == T_RED_OUT || token->type == T_RED_INP
		|| token->type == T_DELIM || token->type == T_APPEND)
		return (1);
	return (0);
}

int	this_token_prec(t_token *token)
{
	if (!token->type)
		return (0);
	if (token->type == T_OR || token->type == T_AND)
		return (1);
	return (0);
}

t_tree_type	token_t_to_tree_t(t_token_type type)
{
	if (type == T_AND)
		return (N_AND);
	if (type == T_OR)
		return (N_OR);
	return (N_PIPE);
}

t_dir_type	token_t_to_tree_dir_t(t_token_type type)
{
	if (type == T_RED_INP)
		return (DIR_IN);
	if (type == T_RED_OUT)
		retrun (DIR_OUT);
	if (type == T_DELIM)
		retrun (DIR_DELIM);
	retrun (DIR_APPEND);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:37:15 by vgabovs           #+#    #+#             */
/*   Updated: 2024/09/25 00:19:57 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envlst	*ft_envlstlast(t_envlst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_envlstadd_back(t_envlst **lst, t_envlst *new)
{
	t_envlst	*last;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else if (new)
	{
		last = ft_envlstlast(*lst);
		last->next = new;
	}
}

t_envlst	*ft_envlstnew(char *name, char *value, int is_shlvl)
{
	t_envlst	*elem;
	int			lvl;

	elem = malloc(sizeof(t_envlst));
	if (elem == NULL)
		return (NULL);
	elem->name = ft_strdup(name);
	if (ft_strncmp(name, "SHLVL", ft_strlen(name)) == 0 && is_shlvl)
	{
		lvl = ft_atoi(value);
		elem->value = ft_itoa(lvl + 1);
	}
	else
	{
		if (!value)
			elem->value = ft_strdup("");
		else
			elem->value = ft_strdup(value);
	}
	elem->next = NULL;
	return (elem);
}

t_envlst *crt_envlst(char **envp)
{
	int			i;
	int			j;
	t_envlst	*envlst;
	char		*name;
	char		*value;

	envlst = NULL;
	i = -1;
	while (envp[++i])
	{
		j = 0;
		while(envp[i][j] && envp[i][j] != '=')
			j++;
		name = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]));
		ft_envlstadd_back(&envlst, ft_envlstnew(name, value, 1));
		free(name);
		free(value);
	}
	return(envlst);
}

void	print_lst(t_envlst *envlst)
{
	t_envlst *tmp;

	tmp = envlst;
	while(tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void	ft_free_envlst(t_envlst **lst)
{
	t_envlst	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		if (temp->name)
			free(temp->name);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}

char	*find_env_value(char *name, t_envlst *envlst)
{
	t_envlst	*tmp;
	int			name_len;
	int			env_name_len;

	name_len = ft_strlen(name);
	tmp = envlst;
	while (tmp)
	{
		env_name_len = ft_strlen(tmp->name);
		if (env_name_len == name_len && ft_strncmp(name, tmp->name, name_len) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	unset_env_name_value(char *name, t_envlst *envlst)
{
	t_envlst	*tmp;
	t_envlst	**lst_ptr;
	int			name_len;

	if (find_env_value(name, envlst) == NULL)
		return ;
	name_len = ft_strlen(name);
	lst_ptr = &envlst;
	while (*lst_ptr)
	{
		if (ft_strncmp(name, (*lst_ptr)->name, name_len) == 0)
		{
			tmp = *lst_ptr;
			(*lst_ptr) = tmp->next;
			free(tmp->value);
			free(tmp->name);
			free(tmp);
			tmp = NULL;
			return ;
		}
		lst_ptr = &((*lst_ptr)->next);
	}
}

void	set_env_name_value(char *name, char *value, t_envlst *envlst)
{
	t_envlst	*tmp;

	tmp = envlst;
	if (!name || name[0] == '\0')
		return ;
	if (find_env_value(name, tmp) != NULL)
		unset_env_name_value(name, envlst);
	ft_envlstadd_back(&envlst, ft_envlstnew(name, value, 0));
}

// int main(int argc, char **argv, char **envp)
// {
// 	t_envlst *a = crt_envlst(envp);
// 	print_lst(a);
// 	set_env_name_value("TEST_NAME", "TEST_VALUE", a);
// 	printf("\n\n------------------------------------\n");
// 	print_lst(a);
// 	printf("------------------------------------\n\n");
// 	set_env_name_value("TEST_NAME", "OTHER_VALUE", a);
// 	set_env_name_value("TEST_NA", "OTHER_VALUE!!!!!", a);
// 	printf("\n\n------------------------------------\n");
// 	print_lst(a);
// 	printf("------------------------------------\n\n");
// 	set_env_name_value("2TEST_NAME", "TEST_VALUE", a);
// 	unset_env_name_value("TEST_NAME", a);
// 	set_env_name_value("", "", a);
// 	set_env_name_value("EMPTY_VAL", "", a);
// 	print_lst(a);
// 	printf("------------------------------------\n\n");
// 	printf("print empty val:%s|\n", find_env_value("EMPTY_VAL", a));
// 	ft_free_envlst(&a);
// }

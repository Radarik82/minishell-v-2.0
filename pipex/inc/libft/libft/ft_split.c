/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:33 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/09 21:05:31 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		count = 1;
	while (s[++i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	}
	return (count);
}

char	**free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**word_split(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i)
		{
			res[j] = ft_substr(s, start, i - start);
			if (res[j] == NULL)
				return (free_mem(res));
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (word_split(res, s, c));
}

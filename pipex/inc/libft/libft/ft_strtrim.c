/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:20:53 by vgabovs           #+#    #+#             */
/*   Updated: 2023/08/12 21:07:13 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start_trim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	set_len;
	size_t	i;
	size_t	j;
	int		trim;

	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	trim = 0;
	i = 0;
	j = 0;
	while (i < s1_len && j < set_len)
	{
		if (s1[i] == set[j])
		{
			trim++;
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (trim);
}

int	end_trim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	set_len;
	size_t	j;
	int		trim;

	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	trim = 0;
	j = 0;
	while (s1_len > 0 && j < set_len)
	{
		if (s1[s1_len - 1] == set[j])
		{
			trim++;
			s1_len--;
			j = 0;
		}
		else
			j++;
	}
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = start_trim(s1, set);
	end = end_trim(s1, set);
	len = ft_strlen(s1) - start - end;
	res = ft_substr(s1, start, len);
	return (res);
}

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

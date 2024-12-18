/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:40:12 by vgabovs           #+#    #+#             */
/*   Updated: 2023/08/12 19:05:34 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
// {
// 	size_t	i;
// 	size_t	strl;

// 	if (needle[0] == '\0')
// 		return ((char *)haystack);
// 	if (haystack[0])
// 		;
// 	i = 0;
// 	strl = ft_strlen(needle);
// 	while ((i + strl) <= len && haystack[i])
// 	{
// 		if (ft_strncmp((char *)&haystack[i], needle, strl) == 0)
// 			return ((char *)&haystack[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

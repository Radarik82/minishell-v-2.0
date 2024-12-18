/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:38:38 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/15 16:16:19 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_safe(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strcpy(char *dst, char const *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*return_str;
// 	int		len;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	return_str = malloc(sizeof(char) * len + 1);
// 	if (!return_str)
// 		return (NULL);
// 	ft_strcpy(return_str, s1);
// 	len = ft_strlen(return_str);
// 	ft_strcpy(&return_str[len], s2);
// 	return (return_str);
// }

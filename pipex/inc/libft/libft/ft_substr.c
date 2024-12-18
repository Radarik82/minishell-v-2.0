/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:31:36 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/09 21:06:22 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	l;

	if (!s && !start)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (l - start < len)
		len = l - start;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

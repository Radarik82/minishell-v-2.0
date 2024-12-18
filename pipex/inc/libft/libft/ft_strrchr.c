/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:36:53 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/17 23:33:14 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = ft_strlen(s);
// 	if (i == 0 && (char)c != '\0')
// 		return (NULL);
// 	if (c == '\0')
// 		return ((char *)&s[i]);
// 	while (i > 0)
// 	{
// 		if ((char)c == s[i])
// 			return ((char *)&s[i]);
// 		i--;
// 	}
// 	if (i == 0 && (char)c == s[i])
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			t = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		t = ((char *)&s[i]);
	return (t);
}

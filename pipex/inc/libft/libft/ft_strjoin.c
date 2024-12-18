/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:20:41 by vgabovs           #+#    #+#             */
/*   Updated: 2023/07/11 13:24:18 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	size_t		res_len;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res_len = s1_len + s2_len;
	res = malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res, s2, res_len + 1);
	return (res);
}

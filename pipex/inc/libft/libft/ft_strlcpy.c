/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:50:03 by vgabovs           #+#    #+#             */
/*   Updated: 2023/08/13 21:58:21 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	if (src_size < dstsize)
	{
		ft_memcpy(dst, src, src_size + 1);
		return (src_size);
	}
	ft_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (src_size);
}

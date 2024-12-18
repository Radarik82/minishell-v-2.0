/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:18:12 by vgabovs           #+#    #+#             */
/*   Updated: 2023/07/02 23:59:13 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	total_size;

	total_size = count * size;
	res = malloc(total_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, total_size);
	return ((void *)res);
}

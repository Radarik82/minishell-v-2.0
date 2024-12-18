/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:26:15 by vgabovs           #+#    #+#             */
/*   Updated: 2023/08/09 22:42:21 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_zero(char base)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * 2);
	if (a == NULL)
		return (NULL);
	a[0] = base;
	a[1] = '\0';
	return (a);
}

int	if_neg(long int *num, int *return_len)
{
	*return_len = 1;
	*num *= -1;
	return (1);
}

int	count_base(long int num, int base_l)
{
	long int	return_len;

	return_len = 0;
	while (num > 0)
	{
		num /= base_l;
		return_len++;
	}
	return (return_len);
}

char	*itoa_base(long int num, char *base)
{
	int		return_len;
	int		base_l;
	int		is_negative;
	char	*a;

	return_len = 0;
	is_negative = 0;
	base_l = ft_strlen(base);
	if (num == 0)
		return (if_zero(base[0]));
	if (num < 0)
		is_negative = if_neg(&num, &return_len);
	return_len += count_base(num, base_l);
	a = (char *)malloc(sizeof(char) * return_len + 1);
	if (a == NULL)
		return (NULL);
	a[return_len] = '\0';
	while (num > 0)
	{
		a[--return_len] = base[num % base_l];
		num /= base_l;
	}
	if (is_negative)
		a[--return_len] = '-';
	return (a);
}

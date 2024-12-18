/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:05:26 by vgabovs           #+#    #+#             */
/*   Updated: 2023/07/06 23:09:59 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_count(int *i, int *sign)
{
	int	count;
	int	n;

	n = *i;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*sign = -1;
		n *= -1;
		*i *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		count;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = int_count(&n, &sign);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = '\0';
	if (n == 0)
		res[0] = '0';
	while (count > 0)
	{
		res[count - 1] = n % 10 + 48;
		n /= 10;
		count--;
	}
	if (sign < 0)
		res[0] = '-';
	return (res);
}

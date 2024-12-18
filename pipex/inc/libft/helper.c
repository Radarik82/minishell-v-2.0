/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:55:32 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 14:42:13 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_blist *bl)
{
	bl->dash = 0;
	bl->dot = 0;
	bl->precis = 0;
	bl->hash = 0;
	bl->plus = 0;
	bl->width = 0;
	bl->space = 0;
	bl->zero = 0;
	bl->sign = 0;
}

void	bl_initialize(t_blist *bl)
{
	bl->dash = 0;
	bl->dot = 0;
	bl->precis = 0;
	bl->hash = 0;
	bl->plus = 0;
	bl->width = 0;
	bl->space = 0;
	bl->zero = 0;
	bl->lenght = 0;
	bl->sign = 0;
}

int	width_pri(int len, int width, char c)
{
	int	return_value;

	if (len <= width)
	{
		width -= len;
		return_value = width;
		while (width--)
			ft_putchar_fd(c, 1);
		return (return_value);
	}
	else
		return (0);
}

int	pos_count_base(unsigned long num, int base_l)
{
	unsigned long	return_len;

	return_len = 0;
	while (num > 0)
	{
		num /= base_l;
		return_len++;
	}
	return (return_len);
}

char	*pos_itoa_base(unsigned long num, char *base)
{
	int		return_len;
	int		base_l;
	char	*a;

	return_len = 0;
	base_l = ft_strlen(base);
	if (num == 0)
		return (if_zero(base[0]));
	return_len += pos_count_base(num, base_l);
	a = (char *)malloc(sizeof(char) * return_len + 1);
	if (a == NULL)
		return (NULL);
	a[return_len] = '\0';
	while (num > 0)
	{
		a[--return_len] = base[num % base_l];
		num /= base_l;
	}
	return (a);
}

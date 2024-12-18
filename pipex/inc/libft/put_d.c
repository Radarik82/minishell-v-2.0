/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:16:13 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 19:10:28 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	di_check(t_blist *bl, char *di, int *len)
{
	if (di[0] == '-')
	{
		bl->sign = 1;
		*len -= 1;
	}
	if (bl->dot && !bl->precis && di[0] == '0')
	{
		*len = 0;
		di[0] = '\0';
	}
	if (bl->dot || bl->dash)
		bl->zero = 0;
	if (bl->plus || bl->sign)
		bl->space = 0;
}

void	put_di_width(t_blist *bl, int len)
{
	if (bl->space || bl->plus || bl->sign)
		bl->width--;
	if (len > bl->precis)
		bl->lenght += width_pri((len), (bl->width), ' ');
	else
		bl->lenght += width_pri((bl->precis), (bl->width), ' ');
}

void	put_di2(t_blist *bl, int len, char *di, int i)
{
	if (bl->zero && bl->width > len + bl->plus && bl->width > len + bl->sign)
		bl->lenght += width_pri(len + bl->plus + bl->space, bl->width, '0');
	if (bl->precis > len)
		bl->lenght += width_pri(len, bl->precis, '0');
	if (bl->sign)
	{
		i = 0;
		while (++i < len + 1)
		{
			bl->lenght++;
			ft_putchar_fd(di[i], 1);
		}
	}
	else if (di[0] != '\0')
	{
		i = -1;
		while (++i < len)
		{
			bl->lenght++;
			ft_putchar_fd(di[i], 1);
		}
	}
	if (bl->dash && bl->width > (bl->precis + bl->plus) && bl->width > (len
			+ bl->plus - bl->sign) && !bl->zero)
		put_di_width(bl, len);
}

void	put_di(t_blist *bl)
{
	char	*di;
	int		len;

	di = itoa_base((int)va_arg(bl->arg, int), "0123456789");
	if (di == NULL)
		return ;
	len = ft_strlen(di);
	di_check(bl, &di[0], &len);
	if (bl->space && !bl->plus && !bl->sign)
		bl->lenght += width_pri(1, 2, ' ');
	if (bl->width > len + bl->plus && bl->width > len + bl->sign
		&& !bl->zero && !bl->dash)
		put_di_width(bl, len);
	if (bl->sign || bl->plus)
	{
		if (bl->sign)
			bl->lenght += width_pri(1, 2, '-');
		else
			bl->lenght += width_pri(1, 2, '+');
		bl->plus = 1;
	}
	put_di2(bl, len, di, 0);
	free(di);
}

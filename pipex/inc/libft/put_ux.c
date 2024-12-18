/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:57:17 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 19:29:05 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_convers(t_blist *bl, int len, char *x)
{
	if (bl->dot || bl->dash)
		bl->zero = 0;
	if (bl->hash && !(x[0] == '\0' || x[0] == '0'))
		bl->width -= 2;
	if (bl->width > len && !bl->zero && !bl->dash)
		put_di_width(bl, len);
}

void	put_x(t_blist *bl)
{
	char	*x;
	int		len;

	x = itoa_base((unsigned int)va_arg(bl->arg, unsigned int),
			"0123456789abcdef");
	if (x == NULL)
		return ;
	len = ft_strlen(x);
	if (bl->dot && !bl->precis && x[0] == '0')
	{
		len = 0;
		x[0] = '\0';
	}
	x_convers(bl, len, x);
	if (bl->hash && !(x[0] == '\0' || x[0] == '0'))
	{
		ft_putstr_fd("0x", 1);
		bl->lenght += 2;
	}
	put_di2(bl, len, x, 0);
	free(x);
}

void	put_cap_x(t_blist *bl)
{
	char	*x;
	int		len;

	x = itoa_base((unsigned int)va_arg(bl->arg, unsigned int),
			"0123456789ABCDEF");
	if (x == NULL)
		return ;
	len = ft_strlen(x);
	if (bl->dot && !bl->precis && x[0] == '0')
	{
		len = 0;
		x[0] = '\0';
	}
	x_convers(bl, len, x);
	if (bl->hash && !(x[0] == '\0' || x[0] == '0'))
	{
		ft_putstr_fd("0X", 1);
		bl->lenght += 2;
	}
	put_di2(bl, len, x, 0);
	free(x);
}

void	put_u(t_blist *bl)
{
	char			*d;
	int				len;
	unsigned int	num;

	num = (unsigned int)(va_arg(bl->arg, unsigned int));
	d = pos_itoa_base(num, "0123456789");
	if (d == NULL)
		return ;
	len = ft_strlen(d);
	di_check(bl, d, &len);
	if (bl->width > len + bl->plus && bl->width > len + bl->sign
		&& !bl->zero && !bl->dash)
		put_di_width(bl, len);
	put_di2(bl, len, d, 0);
	free(d);
}

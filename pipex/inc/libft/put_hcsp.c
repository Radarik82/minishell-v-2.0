/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hcsp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:54:00 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 15:54:20 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_p(t_blist *mark)
{
	unsigned long	p;
	int				len;
	char			*address;

	p = (unsigned long)va_arg(mark->arg, void *);
	address = pos_itoa_base(p, "0123456789abcdef");
	if (address == NULL)
		return ;
	len = ft_strlen(address) + 2;
	if (mark->width > len && !mark->dash)
		mark->lenght += width_pri(len, mark->width, ' ');
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(address, 1);
	if (mark->width > len && mark->dash)
		mark->lenght += width_pri(len, mark->width, ' ');
	free(address);
	mark->lenght += len;
}

void	put_s(t_blist *bl)
{
	char	*str;
	int		len;
	int		i;

	str = (char *)va_arg(bl->arg, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (bl->precis < len && bl->dot)
		len = bl->precis;
	if (bl->width && !bl->dash)
		bl->lenght += width_pri(len, bl->width, ' ');
	i = -1;
	while (++i < len)
	{
		bl->lenght++;
		ft_putchar_fd(str[i], 1);
	}
	if (bl->width && bl->dash)
		bl->lenght += width_pri(len, bl->width, ' ');
}

void	put_c(t_blist *bl)
{
	char	c;

	c = (char)va_arg(bl->arg, int);
	if (bl->width && !bl->dash)
		bl->lenght += width_pri(1, bl->width, ' ');
	ft_putchar_fd(c, 1);
	bl->lenght++;
	if (bl->width && bl->dash)
		bl->lenght += width_pri(1, bl->width, ' ');
}

void	put_percent(t_blist *bl)
{
	if (bl->width && !bl->dash)
		bl->lenght += width_pri(1, bl->width, ' ');
	ft_putchar_fd('%', 1);
	bl->lenght++;
	if (bl->width && bl->dash)
		bl->lenght += width_pri(1, bl->width, ' ');
}

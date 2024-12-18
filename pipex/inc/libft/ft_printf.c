/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:33:48 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 19:34:20 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_str(const char **str, t_blist *bl)
{
	if (**str == '+' || ft_isdigit(**str) || **str == '.' || **str == ' '
		|| **str == '#' || **str == '-')
		(check_flags_bonus(str, bl));
	if (**str == '%')
		put_percent(bl);
	if (**str == 'c')
		(put_c(bl));
	if (**str == 's')
		(put_s(bl));
	if (**str == 'p')
		(put_p(bl));
	if (**str == 'd' || **str == 'i')
		(put_di(bl));
	if (**str == 'u')
		(put_u(bl));
	if (**str == 'x')
		(put_x(bl));
	if (**str == 'X')
		(put_cap_x(bl));
}

int	destribution_print(const char *str, t_blist *bl)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			reset_flags(bl);
			str++;
			check_str(&str, bl);
		}
		else
		{
			len++;
			ft_putchar_fd(*str, 1);
		}
		str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	t_blist	*bl;

	bl = (t_blist *)malloc(sizeof(t_blist));
	if (bl == NULL)
		return (-1);
	bl_initialize(bl);
	va_start(bl->arg, str);
	len = destribution_print(str, bl);
	len += bl->lenght;
	va_end(bl->arg);
	free(bl);
	return (len);
}

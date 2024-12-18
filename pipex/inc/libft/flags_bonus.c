/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:51:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 14:23:04 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_dot_flag(const char **str, t_blist *bl)
{
	bl->dot = 1;
	(*str)++;
	if (ft_isdigit(**str))
	{
		bl->precis = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		(*str)--;
		return ;
	}
	(*str)--;
}

void	check_flags_bonus(const char **str, t_blist *bl)
{
	while (**str == '+' || ft_isdigit(**str) || **str == '.' || **str == ' '
		|| **str == '#' || **str == '-')
	{
		if (**str == '#')
			bl->hash = 1;
		else if (**str == ' ')
			bl->space++;
		else if (**str == '+')
			bl->plus = 1;
		else if (**str == '.')
			check_dot_flag(str, bl);
		else if (**str == '-')
			bl->dash = 1;
		else if (**str == '0')
			bl->zero = 1;
		else if (ft_isdigit(**str))
		{
			bl->width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			(*str)--;
		}
		(*str)++;
	}
}

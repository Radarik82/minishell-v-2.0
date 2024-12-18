/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:08:16 by vgabovs           #+#    #+#             */
/*   Updated: 2023/09/04 14:27:52 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct t_bonus_list
{
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precis;
	int		lenght;
	int		sign;
	va_list	arg;
}			t_blist;

int		ft_printf(const char *str, ...);
int		destribution_print(const char *str, t_blist *bl);
int		count_base(long int num, int base_l);
int		if_neg(long int *num, int *return_len);
int		width_pri(int len, int width, char c);
int		width_pri(int len, int width, char c);
int		pos_count_base(unsigned long num, int base_l);

char	*if_zero(char base);
char	*pos_itoa_base(unsigned long num, char *base);
char	*itoa_base(long int num, char *base);

void	check_flags_bonus(const char **str, t_blist *bl);
void	bl_initialize(t_blist *bl);
void	check_str(const char **str, t_blist *bl);
void	put_percent(t_blist *bl);
void	di_check(t_blist *bl, char *di, int *len);
void	put_di_width(t_blist *bl, int len);
void	put_di2(t_blist *bl, int len, char *di, int i);
void	put_di(t_blist *bl);
void	check_dot_flag(const char **str, t_blist *bl);
void	reset_flags(t_blist *bl);
void	put_p(t_blist *mark);
void	put_s(t_blist *bl);
void	put_c(t_blist *bl);
void	put_percent(t_blist *bl);
void	put_x(t_blist *bl);
void	put_cap_x(t_blist *bl);
void	put_u(t_blist *bl);

#endif

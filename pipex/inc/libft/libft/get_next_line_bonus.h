/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:37:04 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/17 23:35:12 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
void		free_safe(char **str);
// size_t		ft_strlenn(const char *s);
char		*ft_strcpy(char *dst, char const *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			check_newline(char *line);
char		*reset_line(char *line);
char		*return_fnc(char *line);
char		*check_line(char *line, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
#endif

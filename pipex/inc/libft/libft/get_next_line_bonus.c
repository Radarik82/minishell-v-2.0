/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:36:00 by vgabovs           #+#    #+#             */
/*   Updated: 2023/12/17 23:37:21 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_newline(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*reset_line(char *line)
{
	char	*return_line;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(line);
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (free_safe(&line), NULL);
	return_line = ft_calloc(len - i + 1, sizeof(char));
	i++;
	while (line[i])
		return_line[j++] = line[i++];
	return (free_safe(&line), return_line);
}

char	*return_fnc(char *line)
{
	char	*return_line;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	return_line = (char *)malloc(sizeof(char) * i + 1);
	if (!return_line)
		return (free_safe(&line), NULL);
	return_line[i] = '\0';
	while (--i > -1)
		return_line[i] = line[i];
	return (return_line);
}

char	*check_line(char *line, int fd)
{
	int		rd;
	char	*buff;
	char	*tmp;

	if (check_newline(line))
		return (line);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free_safe(&line), NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (free(buff), free_safe(&line), NULL);
		buff[rd] = '\0';
		tmp = ft_strjoin(line, buff);
		free_safe(&line);
		line = tmp;
		if (!line)
			return (free_safe(&buff), NULL);
		if (check_newline(buff))
			break ;
	}
	return (free_safe(&buff), line);
}

char	*get_next_line(int fd)
{
	static char	*line[2048];
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE < 1 | fd > 2047)
		return (NULL);
	if (!line[fd])
	{
		line[fd] = (char *)malloc(1 * sizeof(char));
		if (!line[fd])
			return (free_safe(&line[fd]), NULL);
		line[fd][0] = '\0';
	}
	line[fd] = check_line(line[fd], fd);
	if (!line[fd])
		return (free_safe(&line[fd]), NULL);
	return_line = return_fnc(line[fd]);
	if (!return_line)
		return (free_safe(&line[fd]), free_safe(&return_line), NULL);
	line[fd] = reset_line(line[fd]);
	return (return_line);
}

// int main()
// {
// 	int fd = open("w2.txt", O_RDONLY );
// 	if (fd < 0)
// 		return(printf("error opening file\n"), 13);
// 	char *str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}

// 	return (0);
// }

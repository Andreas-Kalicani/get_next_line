/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasgjertsenkalicani <andreasgjertse    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:18:56 by akalican          #+#    #+#             */
/*   Updated: 2023/10/23 16:36:13 by andreasgjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>

char	*ft_read_str(int fd, char *lft_str)
{
	char	*buff;
	int		read_byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_byt = 1;
	while (!ft_strchr(lft_str, '\n') && read_byt != 0)
	{
		read_byt = read(fd, buff, BUFFER_SIZE);
		if (read_byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byt] = '\0';
		lft_str = ft_strjoin(lft_str, buff);
	}
	free(buff);
	return (lft_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_line(left_str);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("tests/hello.txt", O_RDONLY);
	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:18:56 by akalican          #+#    #+#             */
/*   Updated: 2023/10/23 12:13:08 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	static char	*lft_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (lft_str == NULL)
		lft_str = ft_read_str(fd, lft_str);
	if (!lft_str)
		return (NULL);
	line = ft_get_line(lft_str);
	lft_str = ft_new_line(lft_str);
	return (line);
}

int	main(void)
{
  char *line;
    int i;
    int fd1;

    fd1 = open("hello.txt", O_RDONLY);
    i = 1;

    while (i < 7)
    {
        line = get_next_line(fd1);

        if (line == NULL) {
            printf("End of file reached.\n");
            break;
        }

        printf("line [%02d]: %s", i, line);
        i++;
    }

    close(fd1);
}
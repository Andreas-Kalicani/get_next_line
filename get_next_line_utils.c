/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:30:53 by akalican          #+#    #+#             */
/*   Updated: 2023/10/24 11:14:41 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*relocate_mem(char *str, char *buff)
{
	size_t	len1;
	char	*result;

	len1 = ft_strlen(str) + ft_strlen(buff);
	result = (char *)malloc(sizeof(char) * (len1 + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

/*char	*ft_strjoin(char *lft_str, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!lft_str)
	{
		lft_str = (char *)malloc(1 * sizeof(char));
		lft_str[0] = '\0';
	}
	if (!lft_str || !buff)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(lft_str) + ft_strlen(buff))
				+ 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (lft_str[i] != '\0')
	{
		result[i] = lft_str[i];
		i++;
	}
	while (buff[j] != '\0')
		result[i++] = buff[j++];
	result[i] = '\0';
	free(lft_str);
	return (result);
} */

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_line(char *lft_str)
{
	int		i;
	char	*result;

	i = 0;
	if (!lft_str[i])
		return (NULL);
	while (lft_str[i] && lft_str[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
	{
		result[i] = lft_str[i];
		i++;
	}
	if (lft_str[i] == '\n')
	{
		result[i] = lft_str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

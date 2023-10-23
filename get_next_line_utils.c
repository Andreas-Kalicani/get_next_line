/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:30:53 by akalican          #+#    #+#             */
/*   Updated: 2023/10/23 11:57:24 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static char	*relocate_mem(char *str, char *buff)
{
	size_t	len1;
	char	*result;

	len1 = ft_strlen(str) + ft_strlen(buff);
	result = (char *)malloc(sizeof(char) * (len1 + 1));
	return (result);
}

char	*ft_strjoin(char *lft_str, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!lft_str || !buff)
		return (NULL);
	result = relocate_mem(lft_str, buff);
	if (!result)
		return (NULL);
	i = 0;
	while (lft_str[i] != '\0')
	{
		result[i] = lft_str[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		result[i] = buff[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
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

 char	*ft_new_line(char *lft_str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
	{
		i++;
	}
	if (!lft_str)
	{
		free(lft_str);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(lft_str) - i + 1));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (lft_str[i])
		result[j++] = lft_str[i++];
	result[j] = '\0';
	free(lft_str);
	return (result);
}

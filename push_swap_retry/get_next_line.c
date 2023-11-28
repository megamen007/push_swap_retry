/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:49:49 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/25 16:48:23 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_save(char *r)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (r[i] && r[i] != '\n')
		i++;
	if (!r[i])
	{
		free(r);
		return (0);
	}
	s = malloc(ft_strlen(r) - i);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (r[i])
		s[j++] = r[i++];
	s[j] = '\0';
	free (r);
	return (s);
}

char	*ft_get_line(char *r)
{
	int		i;
	char	*s;

	i = 0;
	if (!r[i])
		return (NULL);
	while (r[i] && r[i] != '\n')
		i++;
	if (r[i] == '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (r[i] && r[i] != '\n')
	{
		s[i] = r[i];
		i++;
	}
	if (r[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read(int fd, char *r)
{
	char	*buffer;
	int		res;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	res = 1;
	while (!ft_strchr(r, '\n') && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 0)
		{
			free (buffer);
			free (r);
			return (NULL);
		}
		buffer[res] = '\0';
		r = ft_strjoin(r, buffer);
	}
	free(buffer);
	return (r);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	static char	*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	r = ft_read(fd, r);
	if (!r)
		return (NULL);
	ptr = ft_get_line(r);
	r = ft_save(r);
	return (ptr);
}
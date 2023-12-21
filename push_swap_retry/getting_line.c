/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:49:49 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/21 18:28:28 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*getting_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	content;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	bytes = read(fd, &content, BUFFER_SIZE);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes > 0)
	{
		buffer[index++] = content;
		if (content == '\n')
			break ;
		bytes = read(fd, &content, BUFFER_SIZE);
	}
	if (bytes <= 0)
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

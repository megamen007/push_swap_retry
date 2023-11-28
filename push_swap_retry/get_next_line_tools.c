/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:49:43 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/25 16:48:15 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    char *str3;

    i = 0;
    j = 0;
    if (!str1)
    {
        str1 = malloc(sizeof(char) * 1);
        str1[0] = '\0';
    }
    if (!str1 || !str2)
        return (NULL);
    str3 = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
    if (!str3)
    return (NULL);
    while(str1[i])
        str3[j++] = str1[i++];
    i = 0;
    while(str2[i])
        str3[j++]= str2[i++];
    str3[j] = '\0';
    return (str3);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != (char)c)
			i++;
		if (s[i] == (char)c)
			return (1);
	}
    return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] || c_s2[i])
	{
		if (c_s1[i] != c_s2[i])
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (0);
}
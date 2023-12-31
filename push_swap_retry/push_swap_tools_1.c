/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:13:08 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/20 19:31:07 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(const char *str)
{
	int				sign;
	long long int	res;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1])
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - '0');
		else
			exit_();
		i++;
	}
	return (sign * res);
}

static int	word_counter(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	word_length(char const *str, char c)
{
	int	l;

	l = 0;
	while (str[l] && str[l] != c)
		l++;
	return (l);
}

static char	**spliter(char **res, char const *s, char c, int words_count)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	while (*s && *s == c)
		s++;
	while (i < words_count)
	{
		while (*s && *s == c)
			s++;
		word_len = word_length(s, c);
		res[i] = (char *)malloc(sizeof(char) * word_len + 1);
		j = 0;
		while (j < word_len)
		{
			res[i][j] = *s;
			j++;
			s++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = word_counter(s, c);
	if (words_count == 0)
		exit_();
	res = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!res)
		return (NULL);
	res = spliter(res, s, c, words_count);
	return (res);
}

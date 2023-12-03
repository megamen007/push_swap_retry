/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:43:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/01 16:48:39 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	duplicate_element(int *elements, int stack_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (elements[i] == elements[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	out_of_int_range(char **str, int i)
{
	if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
		return (1);
	return (0);
}

int	ft_is_not_digit(int c)
{
	if ((c < '0' && c > '9'))
		return (1);
	return (0);
}

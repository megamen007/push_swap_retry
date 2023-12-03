/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:46:37 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/03 07:21:19 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*fill_elements(char **av, t_stack *stc)
{
	int		i;
	int		j;
	int		k;
	char	**str;
	int		*element;

	element = malloc(sizeof(int) * stc->size);
	i = 1;
	j = 0;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		k = 0;
		while (str[k])
		{
			if (ft_atoi(str[k]) > INT_MAX || ft_atoi(str[k]) < INT_MIN)
				exit_();
			element[j] = ft_atoi(str[k]);
			j++;
			k++;
		}
		free_2d(str);
		i++;
	}
	return (element);
}

int	duplicate_element(int *elements, t_stack *stc)
{
	int	i;
	int	j;

	i = 0;
	while (i < stc->size)
	{
		j = i + 1;
		while (j < stc->size)
		{
			if (elements[i] == elements[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	filling_stack(t_stack *stc, int *element)
{
	int	i;
	int	j;

	i = 0;
	j = stc->size - 1;
	stc->top_a = -1;
	stc->top_b = -1;
	stc->stack_a = malloc(sizeof(int) * stc->size);
	stc->stack_b = malloc(sizeof(int) * stc->size);
	while (i < stc->size)
	{
		stc->stack_a[i] = element[j];
		i++;
		j--;
		stc->top_a++;
	}
	free(element);
}

void	arguments_count(t_stack *stc, char **av)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			j++;
			stc->size++;
		}
		free_2d(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		*element;
	t_stack	*stc;

	(void)ac;
	stc = malloc(sizeof(t_stack));
	arguments_count(stc, av);
	element = fill_elements(av, stc);
	checking_errors(element, stc);
	filling_stack(stc, element);
	if (stc->size == 1)
	{
		free(stc->stack_a);
		free(stc->stack_b);
		free(stc);
	}
	checker(stc);
	free(stc->stack_a);
	free(stc->stack_b);
	free(stc);
}

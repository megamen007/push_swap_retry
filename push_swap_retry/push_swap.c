/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:54:52 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/21 18:27:08 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*elements_filling(char **av, int stack_size)
{
	int		i;
	int		j;
	int		k;
	int		*elements;
	char	**str;

	elements = malloc(stack_size * sizeof(int));
	if (!elements)
		return (NULL);
	i = 1;
	j = 0;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		k = 0;
		while (str[k])
		{
			if (out_of_int_range(str, k))
				exit_();
			elements[j++] = ft_atoi(str[k++]);
		}
		free_2d(str);
		i++;
	}
	return (elements);
}

void	checking_errors(int *elements, int stack_size)
{
	if (duplicate_element(elements, stack_size) == 0)
		exit_();
}

void	filling_stack(t_stack *stack, int *element)
{
	int	i;
	int	j;

	i = 0;
	j = stack->stack_size - 1;
	stack->top_a = -1;
	stack->top_b = -1;
	stack->stack_a = malloc(sizeof(int) * stack->stack_size);
	if (!stack->stack_a)
		return ;
	stack->stack_b = malloc(sizeof(int) * stack->stack_size);
	if (!stack->stack_a)
		return ;
	while (i < stack->stack_size)
	{
		stack->stack_a[i] = element[j];
		i++;
		j--;
		stack->top_a++;
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
			stc->stack_size++;
		}
		free_2d(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		*elements;

	(void)ac;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	arguments_count(stack, av);
	elements = elements_filling(av, stack->stack_size);
	checking_errors(elements, stack->stack_size);
	filling_stack(stack, elements);
	if (checking_is_already_backsorted(stack) && stack->stack_size > 5)
		sorting_backsorted_stack(stack);
	if (checking_is_already_sorted(stack))
		sorting_algorithm(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	return (0);
}

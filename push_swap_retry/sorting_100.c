/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:58:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/03 06:21:22 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting100_a_to_b(t_stack *stack)
{
	int	min;
	int	max;

	min = 0;
	max = 15;
	indexing_stack(stack);
	while (stack->top_a + 1)
	{
		if (stack->stack_a[stack->top_a] >= min
			&& stack->stack_a[stack->top_a] <= max)
		{
			pb(stack);
			min++;
			max++;
		}
		else if (stack->stack_a[stack->top_a] < min)
		{
			pb(stack);
			rb(stack);
			min++;
			max++;
		}
		else if (stack->stack_a[stack->top_a] > max)
			ra(stack);
	}
}

void	sorting500_a_to_b(t_stack *stack)
{
	int	min;
	int	max;

	min = 0;
	max = 35;
	indexing_stack(stack);
	while (stack->top_a + 1)
	{
		if (stack->stack_a[stack->top_a] >= min
			&& stack->stack_a[stack->top_a] <= max)
		{
			pb(stack);
			min++;
			max++;
		}
		else if (stack->stack_a[stack->top_a] < min)
		{
			pb(stack);
			rb(stack);
			min++;
			max++;
		}
		else if (stack->stack_a[stack->top_a] > max)
			ra(stack);
	}
}

void	updated_stack(t_stack *stack, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->stack_size)
	{
		j = 0;
		while (j < stack->stack_size)
		{
			if (stack->stack_a[i] == arr[j])
			{
				stack->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(arr);
}

void	sorting_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing_stack(t_stack *stack)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * stack->stack_size);
	if (arr == NULL)
		return ;
	while (i < stack->stack_size)
	{
		arr[i] = stack->stack_a[i];
		i++;
	}
	sorting_array(arr, stack->stack_size);
	updated_stack(stack, arr);
}

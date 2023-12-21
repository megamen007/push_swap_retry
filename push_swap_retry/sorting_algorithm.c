/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:25:20 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/20 18:54:28 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(t_stack *stack)
{
	if (stack->stack_size == 2)
		sorting_2(stack);
	else if (stack->stack_size == 3)
		sorting_3(stack);
	else if (stack->stack_size == 4)
		sorting_4(stack);
	else if (stack->stack_size == 5)
		sorting_5(stack);
	else if (stack->stack_size > 5 && stack->stack_size <= 100)
	{
		sorting100_a_to_b(stack);
		sorting100_b_to_a(stack);
	}
	else if (stack->stack_size > 100)
	{
		sorting500_a_to_b(stack);
		sorting500_b_to_a(stack);
	}
}

void	sorting_2(t_stack *stack)
{
	sa(stack);
}

void	sorting_3(t_stack *stack)
{
	int	place0;
	int	place1;
	int	place2;

	place0 = stack->stack_a[0];
	place1 = stack->stack_a[1];
	place2 = stack->stack_a[2];
	if (place2 > place1 && place1 < place0 && place0 > place2)
		sa(stack);
	else if (place2 > place1 && place1 > place0 && place0 < place2)
	{
		sa(stack);
		rra(stack);
	}
	else if (place2 > place1 && place1 < place0 && place0 < place2)
		ra(stack);
	else if (place2 < place1 && place1 > place0 && place0 > place2)
	{
		sa(stack);
		ra(stack);
	}
	else if (place2 < place1 && place1 > place2 && place0 < place2)
		rra(stack);
}

void	sorting_4(t_stack *stack)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = stack->stack_a[i];
	while (i <= stack->top_a)
	{
		if (stack->stack_a[i] < lowest)
			lowest = stack->stack_a[i];
		i++;
	}
	while (stack->stack_a[stack->top_a] != lowest)
		ra(stack);
	pb(stack);
	sorting_3(stack);
	pa(stack);
}

void	sorting_5(t_stack *stack)
{
	indexing_stack(stack);
	while (stack->stack_a[stack->top_a] <= 2)
		ra(stack);
	pb(stack);
	while (stack->stack_a[stack->top_a] <= 2)
		ra(stack);
	pb(stack);
	if (stack->stack_b[stack->top_b] > stack->stack_b[stack->top_b - 1])
		sb(stack);
	sorting_3(stack);
	pa(stack);
	ra(stack);
	pa(stack);
	ra(stack);
}

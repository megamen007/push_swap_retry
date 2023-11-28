/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:54:52 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/25 16:39:18 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *elements_filling(char **av, int stack_size)
{
    int i;
    int j;
    int k;
    int *elements;
    char **str;

    elements = malloc(stack_size * sizeof(int));
    i = 1;  // we initialise i = 1 because av[0] equal program name !
    j = 0;
    while(av[i])
    {
        str = ft_split(av[i], ' ');
        k = 0;
        while(str[k])
        {
            if (ft_atoi(str[k]) > INT_MAX || ft_atoi(str[k]) < INT_MIN)
				exit_();
            elements[j++] = ft_atoi(str[k++]);
        }
        i++;
    }
    return(elements);
}
void checking_errors(int *elements, int stack_size)
{
    if (duplicate_element(elements , stack_size) == 0)
        exit_();
    // else if (out_of_int_range(elements) == 0)
    //     exit_();
}

void filling_stack(t_stack *stack, int *element)
{
    int i;
    int j;
    
    i = 0;
    j = stack->stack_size - 1;
    stack->top_a = -1; // when we initialise top_a and top-B to -1 we claim that this stack are still empty 
    stack->top_b = -1;
    stack->stack_a = malloc(sizeof(int) * stack->stack_size);
    stack->stack_b = malloc(sizeof(int) * stack->stack_size);
    while(i < stack->stack_size)
    {
        stack->stack_a[i] = element[j];
        i++;
        j--;
        stack->top_a++;
    }
}
void	print_stack(t_stack *stacks)
{
	int	i;

	i = stacks->stack_size - 1;
	while (i >= 0)
	{
		printf("A-->%i\n", stacks->stack_a[i]);
		i--;
	}
}

void	print_stack_b(t_stack *stacks)
{
	int	i;

	i = stacks->stack_size - 1;
	while (i >= 0)
	{
		printf("B-->%i\n", stacks->stack_b[i]);
		i--;
	}
}

int main (int ac, char **av)
{
    t_stack *stack;
    int *elements;

    stack = malloc(sizeof(t_stack));
    stack->stack_size = ac - 1;
    elements = elements_filling(av, stack->stack_size);
    checking_errors(elements, stack->stack_size);
    filling_stack(stack, elements);
    checking_is_already_sorted(stack);
    if (checking_is_already_backsorted(stack))
        sorting_backsorted_stack(stack);
    else
        sorting_algorithm(stack);
}